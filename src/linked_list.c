// PREPROCESSOR {{{1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"
#include "debug.h"

// DEBUG {{{1

#if defined(DEBUG_LLT)

static bool zz_llt_snew(void);
static bool zz_llt_sprint(void);
static bool zz_llt_sfree(void);

static bool zz_slist(struct llt_snode ** head);


bool
llt_test(void) {
	return zz_llt_sfree();
	//return zz_llt_sprint();
	//return zz_llt_snew();
}


static bool
zz_llt_snew(void) {
	struct llt_snode * node;
	if (!llt_snew(&node)) {
		return false;
	}
	printf("%d\n", node->data);
	free(node);
	return true;
}


static bool
zz_llt_sprint(void) {
	struct llt_snode * node = NULL;
	if (! zz_slist(&node)) {
		return false;
	}
	llt_sprint(node);
	return true;
}


static bool
zz_slist(struct llt_snode ** head) {
	const int MAX_NODE = 10;
	struct llt_snode * nodes[MAX_NODE];
	bool is_ok = true;
	for (int i = 0; i < MAX_NODE; i++) {
		if (! llt_snew(&nodes[i])) {
			is_ok = false;
			goto FREE;
		}
		nodes[i]->data = i + 42;
	}
	for (int i = 0; i < MAX_NODE-1; i++) {
		nodes[i]->next = nodes[i+1];
	}
	*head = nodes[0];
	return is_ok;

FREE:
	for (int i = 0; i < MAX_NODE; i++) {
		if (nodes[i]) {
			free(nodes[i]);
		}
	}
	*head = NULL;
	return is_ok;
}


static bool
zz_llt_sfree(void) {
	struct llt_snode * node = NULL;
	bool is_ok = false;
	if (! zz_slist(&node)) {
		return is_ok;
	}
	llt_sprint(node);

	printf("\n");
	if (! llt_sfree(&node)) {
		fprintf(stderr, "Failed: llt_sfree()");
	} else if (node != NULL) {
		fprintf(stderr, "Node is NOT NULL");
	} else {
		is_ok = true;
	}
	return is_ok;
}

#endif

// SNODE {{{1

bool
llt_snew(struct llt_snode ** node) {
	*node = malloc(sizeof(struct llt_snode));
	if (! *node) {
		fprintf(stderr, "Memory error");
		return false;
	}
	(*node)->data = 0;
	(*node)->next = NULL;
	return true;
}


void
llt_sprint(struct llt_snode * node) {
	struct llt_snode * this = node;
	for (int i = 0; this; i++) {
		printf("%d: %d\n", i, this->data);
		this = this->next;
	}
}


bool
llt_sfree(struct llt_snode ** node) {
	struct llt_snode * head = *node;
	struct llt_snode * child = NULL;
#if defined(DEBUG_LLT)
	int i = 0;
#endif
	while (head) {
#if defined(DEBUG_LLT)
		printf("Del %d: %d\n", i, head->data);
		i++;
#endif
		child = head->next;
		free(head);
		head = child;
	}
	*node = NULL;
	return true;
}
