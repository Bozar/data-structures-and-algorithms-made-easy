// PREPROCESSOR {{{1

#ifndef STACK_H
#define STACK_H


#include <stdbool.h>

#include "debug.h"
// DEBUG {{{1

#if DEBUG_STK

bool stk_test(void);

#endif
// LINKED_LIST {{{1

struct stk_lstack {
	struct llt_snode * top;
	int size;
};

bool stk_lnew(struct stk_lstack ** stack);
bool stk_lpush(struct stk_lstack * stack, int data);
bool stk_lpop(struct stk_lstack * stack, int * data);
bool stk_lpeek(struct stk_lstack * stack, int * data);
bool stk_lis_empty(struct stk_lstack * stack);
int stk_lsize(struct stk_lstack * stack);
void stk_lfree(struct stk_lstack ** stack);
// EOF {{{1

#endif // STACK_H
