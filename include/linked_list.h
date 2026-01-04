#ifndef LINKED_LIST_H
#define LINKED_LIST_H


#include <stdbool.h>


//#define NDEBUG


#ifndef NDEBUG

bool llt_test(void);

#endif // NDEBUG


struct llt_snode {
	int data;
	struct llt_snode * next;
};

bool llt_snew(struct llt_snode ** node);
void llt_sprint(const struct llt_snode * node);


#endif // LINKED_LIST_H
