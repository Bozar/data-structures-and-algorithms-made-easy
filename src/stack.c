// PREPROCESSOR {{{1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"
#include "linked_list.h"

#define INIT_SIZE 8
// DEBUG {{{1
// MARCO {{{2

#if DEBUG_STK
NO_WARNING_BEGIN
NO_WARNING(-Wunused-function)
// ZZ_STK_LINKED_LIST {{{2

// new(), is_empty(), size(), free()
static bool zz_stk_lnew(struct stk_lstack ** stack);
static bool zz_stk_loperate(void);


static bool
zz_stk_lnew(struct stk_lstack ** stack) {
	if (! stk_lnew(stack)) {
		PRINT_ERR("Failed: stk_lnew()");
		assert(false);
	} else if (! stk_lis_empty(*stack)) {
		PRINT_ERR("Failed: stk_lis_empty()");
		assert(false);
	} else if (stk_lsize(*stack) != 0) {
		PRINT_ERR("Failed: stk_lsize()");
		assert(false);
	}
	stk_lfree(stack);
	if (*stack != NULL) {
		PRINT_ERR("Failed: stk_lfree()");
		assert(false);
	}
	PRINT_LOG("Passed.");
	return true;
}


static bool
zz_stk_loperate(void) {
	struct stk_lstack * stack = NULL;
	bool is_ok = false;
	if (! stk_lnew(&stack)) {
		PRINT_ERR("Failed: stk_lnew()");
		goto CLEAN_UP;
	}

	int data = -1;
	for (int i = 0; i < 9; i++) {
		if (! stk_lpush(stack, i)) {
			PRINT_ERR("Failed: stk_lpush()");
			goto CLEAN_UP;
		} else if (stk_lis_empty(stack)) {
			PRINT_ERR("Failed: stk_lis_empty()");
			goto CLEAN_UP;
		} else if (stk_lsize(stack) != i+1) {
			PRINT_ERR("Failed: stk_lsize()");
			goto CLEAN_UP;
		}
		data = -1;
		if ((! stk_lpeek(stack, &data)) || (data != i)) {
			PRINT_ERR("Failed: stk_lpeek()");
			goto CLEAN_UP;
		}
	}

	for (int i = 8; i > 0; i--) {
		data = -1;
		if ((! stk_lpop(stack, &data)) || (data != i)) {
			PRINT_ERR("Failed: stk_lpop()");
			goto CLEAN_UP;
		} else if (stk_lis_empty(stack)) {
			PRINT_ERR("Failed: stk_lis_empty()");
			goto CLEAN_UP;
		} else if (stk_lsize(stack) != i) {
			PRINT_ERR("Failed: stk_lsize()");
			goto CLEAN_UP;
		}
		data = -1;
		if ((! stk_lpeek(stack, &data)) || (data != i-1)) {
			PRINT_ERR("Failed: stk_lpeek()");
			goto CLEAN_UP;
		}
	}
	data = -1;
	if ((! stk_lpop(stack, &data)) || (data != 0)) {
		PRINT_ERR("Failed: stk_lpop()");
		goto CLEAN_UP;
	}

	if (stk_lpop(stack, &data)) {
		PRINT_ERR("Failed: stk_lpop()");
		goto CLEAN_UP;
	} else if (! stk_lis_empty(stack)) {
		PRINT_ERR("Failed: stk_lis_empty()");
		goto CLEAN_UP;
	} else if (stk_lsize(stack) != 0) {
		PRINT_ERR("Failed: stk_lsize()");
		goto CLEAN_UP;
	} else if (stk_lpeek(stack, &data)) {
		PRINT_ERR("Failed: stk_lpeek()");
		goto CLEAN_UP;
	}

	is_ok = true;
CLEAN_UP:
	stk_lfree(&stack);
	if (is_ok) {
		PRINT_LOG("Passed.");
	}
	return is_ok;
}
// ZZ_STK_ARRAY {{{2

// new(), is_empty(), size(), free()
static bool zz_stk_anew(struct stk_astack ** stack);
static bool zz_stk_aoperate(void);


static bool
zz_stk_anew(struct stk_astack ** stack) {
	if (! stk_anew(stack)) {
		PRINT_ERR("Failed: stk_anew()");
		assert(false);
	} else if (! stk_ais_empty(*stack)) {
		PRINT_ERR("Failed: stk_ais_empty()");
		assert(false);
	} else if (stk_asize(*stack) != 0) {
		PRINT_ERR("Failed: stk_asize()");
		assert(false);
	}
	stk_afree(stack);
	if (*stack != NULL) {
		PRINT_ERR("Failed: stk_afree()");
		assert(false);
	}
	PRINT_LOG("Passed.");
	return true;
}


static bool
zz_stk_aoperate(void) {
	struct stk_astack * stack = NULL;
	bool is_ok = false;
	if (! stk_anew(&stack)) {
		PRINT_ERR("Failed: stk_anew()");
		goto CLEAN_UP;
	}

	int data = -1;
	for (int i = 0; i < 9; i++) {
		if (! stk_apush(stack, i)) {
			PRINT_ERR("Failed: stk_apush()");
			goto CLEAN_UP;
		} else if (stk_ais_empty(stack)) {
			PRINT_ERR("Failed: stk_ais_empty()");
			goto CLEAN_UP;
		} else if (stk_asize(stack) != i+1) {
			PRINT_ERR("Failed: stk_asize()");
			goto CLEAN_UP;
		}
		data = -1;
		if ((! stk_apeek(stack, &data)) || (data != i)) {
			PRINT_ERR("Failed: stk_apeek()");
			goto CLEAN_UP;
		}
	}

	for (int i = 8; i > 0; i--) {
		data = -1;
		if ((! stk_apop(stack, &data)) || (data != i)) {
			PRINT_ERR("Failed: stk_apop()");
			goto CLEAN_UP;
		} else if (stk_ais_empty(stack)) {
			PRINT_ERR("Failed: stk_ais_empty()");
			goto CLEAN_UP;
		} else if (stk_asize(stack) != i) {
			PRINT_ERR("Failed: stk_asize()");
			goto CLEAN_UP;
		}
		data = -1;
		if ((! stk_apeek(stack, &data)) || (data != i-1)) {
			PRINT_ERR("Failed: stk_apeek()");
			goto CLEAN_UP;
		}
	}
	data = -1;
	if ((! stk_apop(stack, &data)) || (data != 0)) {
		PRINT_ERR("Failed: stk_apop()");
		goto CLEAN_UP;
	}

	if (stk_apop(stack, &data)) {
		PRINT_ERR("Failed: stk_apop()");
		goto CLEAN_UP;
	} else if (! stk_ais_empty(stack)) {
		PRINT_ERR("Failed: stk_ais_empty()");
		goto CLEAN_UP;
	} else if (stk_asize(stack) != 0) {
		PRINT_ERR("Failed: stk_asize()");
		goto CLEAN_UP;
	} else if (stk_apeek(stack, &data)) {
		PRINT_ERR("Failed: stk_apeek()");
		goto CLEAN_UP;
	}

	is_ok = true;
CLEAN_UP:
	stk_afree(&stack);
	if (is_ok) {
		PRINT_LOG("Passed.");
	}
	return is_ok;
}
// STK_TEST {{{2

bool
stk_test(void) {
//	struct stk_astack * stack = NULL;
//	return zz_stk_anew(&stack);
	return zz_stk_aoperate();

//	struct stk_lstack * stack = NULL;
//	return zz_stk_lnew(&stack);
//	return zz_stk_loperate();
}

NO_WARNING_END
#endif // DEBUG_STK
// LINKED_LIST {{{1

bool
stk_lnew(struct stk_lstack ** stack) {
	*stack = malloc(sizeof(struct stk_lstack));
	if (*stack == NULL) {
		PRINT_ERR("Memory error.");
		return false;
	}
	(*stack)->top = NULL;
	(*stack)->size = 0;
	return true;
}


bool
stk_lis_empty(struct stk_lstack * stack) {
	if (stack == NULL) {
		PRINT_ERR("Stack is null.");
		return false;
	}

	bool no_top = (stack->top == NULL);
	bool no_size = (stack->size == 0);
	if (no_top && no_size) {
		return true;
	} else if (no_top ^ no_size) {
		PRINT_ERR("No top: %d, no size: %d", no_top, no_size);
	}
	return false;
}


int
stk_lsize(struct stk_lstack * stack) {
	if (stack == NULL) {
		PRINT_ERR("Stack is null.");
		return -1;
	}
	return stack->size;
}


void
stk_lfree(struct stk_lstack ** stack) {
	if (*stack == NULL) {
		return;
	}

	if ((*stack)->top != NULL) {
		llt_sfree(&((*stack)->top));
		(*stack)->top = NULL;
	}
	free(*stack);
	*stack = NULL;
}


bool
stk_lpush(struct stk_lstack * stack, int data) {
	struct llt_snode * node = NULL;
	if (stack == NULL) {
		PRINT_ERR("Stack is null.");
		return false;
	} else if (! llt_snew(&node)) {
		return false;
	}

	node->data = data;
	node->next = stack->top;
	stack->top = node;
	stack->size += 1;
	return true;
}


bool
stk_lpop(struct stk_lstack * stack, int * data) {
	if (stack == NULL) {
		PRINT_ERR("Stack is null.");
		return false;
	} else if (stack->top == NULL) {
		return false;
	}

	*data = (stack->top)->data;
	stack->top = (stack->top)->next;
	stack->size -= 1;
	return true;
}


bool
stk_lpeek(struct stk_lstack * stack, int * data) {
	if (stack == NULL) {
		PRINT_ERR("Stack is null.");
		return false;
	} else if (stack->top == NULL) {
		return false;
	}

	*data = (stack->top)->data;
	return true;
}
// ARRAY {{{1

bool
stk_anew(struct stk_astack ** stack) {
	*stack = malloc(sizeof(struct stk_astack));
	if (*stack == NULL) {
		PRINT_ERR("Memory error.");
		return false;
	}
	(*stack)->array = malloc(sizeof(int)*INIT_SIZE);
	if ((*stack)->array == NULL) {
		PRINT_ERR("Memory error.");
		return false;
	}
	(*stack)->top = -1;
	(*stack)->max_size = INIT_SIZE;
	return true;
}


bool
stk_ais_empty(struct stk_astack * stack) {
	if (stack == NULL) {
		PRINT_ERR("Stack is null.");
		return false;
	}
	return stack->top < 0;
}


int
stk_asize(struct stk_astack * stack) {
	if (stack == NULL) {
		PRINT_ERR("Stack is null.");
		return -1;
	}
	return (stack->top)+1;
}


void
stk_afree(struct stk_astack ** stack) {
	if (*stack == NULL) {
		return;
	}

	if ((*stack)->array != NULL) {
		free((*stack)->array);
		(*stack)->array = NULL;
	}
	free(*stack);
	*stack = NULL;
}


bool
stk_apush(struct stk_astack * stack, int data) {
	if (stack == NULL) {
		PRINT_ERR("Stack is null.");
		return false;
	}

	int * new_array = NULL;
	if ((stack->top)+1 >= (int)stack->max_size) {
		new_array = realloc(
				stack->array, sizeof(int)*(stack->max_size)*2
		);
		if (new_array == NULL) {
			PRINT_ERR("Memory error.");
			return false;
		}
		stack->max_size *= 2;
		stack->array = new_array;
	} else if (stack->array == NULL) {
		PRINT_ERR("Array is NULL.");
		return false;
	}

	stack->top += 1;
	(stack->array)[stack->top] = data;
	return true;
}


bool
stk_apop(struct stk_astack * stack, int * data) {
	if (stack == NULL) {
		PRINT_ERR("Stack is null.");
		return false;
	} else if (stack->array == NULL) {
		PRINT_ERR("Array is NULL.");
		return false;
	} else if (stack->top < 0) {
		return false;
	}

	*data = (stack->array)[stack->top];
	(stack->array)[stack->top] = 0;
	stack->top -= 1;
	return true;
}


bool
stk_apeek(struct stk_astack * stack, int * data) {
	if (stack == NULL) {
		PRINT_ERR("Stack is null.");
		return false;
	} else if (stack->array == NULL) {
		PRINT_ERR("Array is NULL.");
		return false;
	} else if ((stack->top < 0) || (stack->top+1 > (int)stack->max_size)) {
		return false;
	}

	*data = (stack->array)[stack->top];
	return true;
}
