// PREPROCESSOR {{{1

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

//#define NDEBUG
//#include <assert.h>

#include <stdbool.h>

// DEBUG {{{1

#if ! defined(NDEBUG)

bool llt_test(void);

#endif // NDEBUG

// SNODE {{{1

struct llt_snode {
	int data;
	struct llt_snode * next;
};

bool llt_snew(struct llt_snode ** node);
void llt_sprint(struct llt_snode * node);
bool llt_sfree(struct llt_snode ** node);

// EOF {{{1

#endif // LINKED_LIST_H
