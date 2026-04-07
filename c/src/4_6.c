#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"
#include "utility.h"


struct mins_stack {
	struct stk_astack * stack;
	struct stk_astack * min;
};

static bool mins_new(struct mins_stack ** stack);
static bool mins_push(struct mins_stack * stack, int data);
static bool mins_pop(struct mins_stack * stack, int * data);
static bool mins_min(struct mins_stack * stack, int * data);


static bool
mins_new(struct mins_stack ** stack) {
	*stack = malloc(sizeof(struct mins_stack));
	if (
			(*stack == NULL)
			|| (! stk_anew(&((*stack)->stack)))
			|| (! stk_anew(&((*stack)->min)))
	) {
		PRINT_ERR("Memory error.");
		return false;
	}
	return true;
}


static bool
mins_push(struct mins_stack * stack, int data) {
	int min = 0;
	if (! stk_apush(stack->stack, data)) {
		PRINT_ERR("Error: mins_push().");
		return false;
	}
	if (stk_ais_empty(stack->min)) {
		min = data;
	} else {
		stk_apeek(stack->min, &min);
	}
	if (data <= min) {
		if (! stk_apush(stack->min, data)) {
			PRINT_ERR("Error: mins_push().");
			return false;
		}
	}
	return true;
}


static bool
mins_pop(struct mins_stack * stack, int * data) {
	int min = 0;
	if (! stk_apop(stack->stack, data)) {
		PRINT_ERR("Error: mins_pop().");
		return false;
	}
	stk_apeek(stack->min, &min);
	if (*data <= min) {
		if (! stk_apop(stack->min, &min)) {
			PRINT_ERR("Error: mins_pop().");
			return false;
		}
	}
	return true;
}


static bool
mins_min(struct mins_stack * stack, int * data) {
	if (! stk_apeek(stack->min, data)) {
		PRINT_ERR("Error: mins_min().");
	}
	return stk_apeek(stack->min, data);
}


int
main(void) {
	struct mins_stack * stack = NULL;
	if (! mins_new(&stack)) {
		exit(EXIT_FAILURE);
	}

	int test[] = {2, 6, 4, 1, 5, 1,};
	int size = SIZE_ARR(test);
	int top = 0;
	int min = 0;

	for (int i = 0; i < size; i++) {
		if (
				(! mins_push(stack, test[i]))
				|| (! mins_min(stack, &min))
		) {
			exit(EXIT_FAILURE);
		}
		stk_apeek(stack->stack, &top);
		PRINT_LOG("i: %d, top: %d, min: %d", i, top, min);
		assert(top == test[i]);
		if (i < 3) {
			assert(min == 2);
		} else if (i > 0) {
			assert(min == 1);
		}
	}

	for (int i = size-1; i > 0; i--) {
		if (
				(! mins_pop(stack, &top))
				|| (! mins_min(stack, &min))
		) {
			exit(EXIT_FAILURE);
		}
		PRINT_LOG("i: %d, top: %d, min: %d", i, top, min);
		if (i > 3) {
			assert(min == 1);
		} else {
			assert(min == 2);
		}
		assert(top == test[i]);
	}

	PRINT_LOG("Passed.");
}
