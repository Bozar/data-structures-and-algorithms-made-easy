// PREPROCESSOR {{{1

#ifndef LINKED_LIST_H
#define LINKED_LIST_H


#include <stdbool.h>

#include "debug.h"
// DEBUG {{{1

#if DEBUG_LLT

bool llt_test(void);

#endif
// SLIST {{{1

struct llt_snode {
	int data;
	struct llt_snode * next;
};

bool llt_snew(struct llt_snode ** node);
void llt_sprint(struct llt_snode * head);
bool llt_sfree(struct llt_snode ** head);
bool llt_sinsert(struct llt_snode ** head, int data, int index);
bool llt_sdelete(struct llt_snode ** head, int index);
// DLIST {{{1

struct llt_dnode {
	int data;
	struct llt_dnode * next;
	struct llt_dnode * prev;
};

bool llt_dnew(struct llt_dnode ** node);
void llt_dprint(struct llt_dnode * head);
bool llt_dfree(struct llt_dnode ** head);
bool llt_dinsert(struct llt_dnode ** head, int data, int index);
bool llt_ddelete(struct llt_dnode ** head, int index);
// EOF {{{1

#endif // LINKED_LIST_H
