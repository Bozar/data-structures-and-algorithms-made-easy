#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#define NDEBUG
//#include <assert.h>

#include "linked_list.h"


#ifndef NDEBUG

static bool zz_snew(void);
static bool zz_sprint(void);


bool
llt_test(void) {
	//return zz_sprint();
	return zz_snew();
}


static bool
zz_snew(void) {
	struct llt_snode * node;
	if (!llt_snew(&node)) {
		return false;
	}
	node->data = 42;
	printf("%d\n", node->data);
	free(node);
	return true;
}


static bool
zz_sprint(void) {
	return true;
}

#endif // NDEBUG


bool
llt_snew(struct llt_snode ** node) {
	*node = malloc(sizeof(struct llt_snode));
	if (! *node) {
		fprintf(stderr, "Memory error");
		return false;
	}
	return true;
}


//void
//llt_sprint(const struct llt_snode * node) {
	//struct llt_snode * next = node;
	//for (int i = 0; next != NULL; ) {
		//printf("%d: %d\n", i, next->data);
		//next = next->next;
		//i += 1;
	//}
//}
