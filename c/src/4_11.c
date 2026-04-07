#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"


static void reverse(struct stk_astack * stack);
static void insert(struct stk_astack * stack, int data);


static void
reverse(struct stk_astack * stack) {
	if (stk_ais_empty(stack)) {
		return;
	}
	int top = 0;
	stk_apop(stack, &top);
	reverse(stack);
	insert(stack, top);
}


static void
insert(struct stk_astack * stack, int data) {
	int top = 0;
	struct stk_astack * save = NULL;
	if (! stk_anew(&save)) {
		return;
	}

	while (! stk_ais_empty(stack)) {
		stk_apop(stack, &top);
		stk_apush(save, top);
	}
	stk_apush(stack, data);
	while (! stk_ais_empty(save)) {
		stk_apop(save, &top);
		stk_apush(stack, top);
	}
}


int
main(void) {
	struct stk_astack * stack = NULL;
	if (! stk_anew(&stack)) {
		exit(EXIT_FAILURE);
	}

	int top = 0;
	for (int i = 1; i < 10; i++) {
		stk_apush(stack, i);
		if (! stk_apeek(stack, &top)) {
			exit(EXIT_FAILURE);
		}
		if (i < 9) {
			PRINT_LOG("Push: %d", top);
		} else {
			PRINT_LOG("Push: %d\n", top);
		}
	}

	reverse(stack);
	for (int i = 1; i < 10; i++) {
		if (! stk_apop(stack, &top)) {
			exit(EXIT_FAILURE);
		}
		PRINT_LOG("Pop: %d", top);
		assert(top == i);
	}
	PRINT_LOG("\n\nPassed.");
	exit(EXIT_SUCCESS);
}
