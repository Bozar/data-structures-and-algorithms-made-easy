// PREPROCESSOR {{{1

#ifndef LINKED_LIST_H
#define LINKED_LIST_H


#include <stdbool.h>

#include "debug.h"

// DEBUG {{{1

#if defined(DEBUG_LLT)

bool llt_test(void);

#endif

// SNODE {{{1

struct llt_snode {
	int data;
	struct llt_snode * next;
};

bool llt_snew(struct llt_snode ** node);
void llt_sprint(struct llt_snode * node);
bool llt_sfree(struct llt_snode ** node);

// EOF {{{1

#endif
