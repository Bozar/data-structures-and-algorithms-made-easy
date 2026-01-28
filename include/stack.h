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
// ARRAY_LIST {{{1

struct stk_astack {
	int top;
	unsigned max_size;
	int * array;
};

bool stk_anew(struct stk_astack ** stack);
bool stk_apush(struct stk_astack * stack, int data);
bool stk_apop(struct stk_astack * stack, int * data);
bool stk_apeek(struct stk_astack * stack, int * data);
bool stk_ais_empty(struct stk_astack * stack);
int stk_asize(struct stk_astack * stack);
void stk_afree(struct stk_astack ** stack);
// EOF {{{1

#endif // STACK_H
