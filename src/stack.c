// PREPROCESSOR {{{1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"
#include "linked_list.h"
// DEBUG {{{1
// MARCO {{{2

#if DEBUG_STK
NO_WARNING_BEGIN
NO_WARNING(-Wunused-function)
// ZZ_STK_LINKED_LIST {{{2

// new(), is_empty(), size(), free()
static bool zz_stk_lnew(struct stk_lstack ** stack);


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
// STK_TEST {{{2

bool
stk_test(void) {
	struct stk_lstack * stack = NULL;
	return zz_stk_lnew(&stack);
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
	return stack->size;
}


void
stk_lfree(struct stk_lstack ** stack) {
	if (*stack == NULL) {
		return;
	}

	if ((*stack)->top != NULL) {
		llt_sfree(&((*stack)->top));
	}
	free(*stack);
	*stack = NULL;
}
