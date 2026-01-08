// PREPROCESSOR {{{1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"
#include "debug.h"
// DEBUG {{{1
// MARCO {{{2

#if DEBUG_LLT
NO_WARNING_BEGIN
NO_WARNING(-Wunused-function)

#define MAX_NODE 10
#define FIRST_DATA 42
// ZZ_SLIST {{{2

static bool zz_llt_snew(void);
static bool zz_llt_sprint(void);
static bool zz_llt_sfree(void);
static bool zz_llt_sinsert(void);
static bool zz_llt_sdelete(void);

static bool zz_slist(struct llt_snode ** head);


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
	struct llt_snode * nodes[MAX_NODE];
	bool is_ok = true;
	for (int i = 0; i < MAX_NODE; i++) {
		if (! llt_snew(&nodes[i])) {
			is_ok = false;
			goto CLEAN_UP;
		}
		nodes[i]->data = i + FIRST_DATA;
	}
	for (int i = 0; i < MAX_NODE-1; i++) {
		nodes[i]->next = nodes[i+1];
	}
	*head = nodes[0];
	return is_ok;

CLEAN_UP:
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
		PRINT_ERROR("Failed: llt_sfree().");
	} else if (node != NULL) {
		PRINT_ERROR("Node is NOT NULL.");
	} else {
		is_ok = true;
	}
	return is_ok;
}


static bool
zz_llt_sinsert(void) {
	// Create a list.
	struct llt_snode * head = NULL;
	bool is_ok = false;
	if (! zz_slist(&head)) {
		goto CLEAN_UP;
	}
	llt_sprint(head);
	printf("\n");

	// Test a negative index.
	const int ERR = -1;
	if (llt_sinsert(&head, ERR, ERR)) {
		assert(false);
	}
	printf("\n");

	// Insert head.
	const int DT0 = 3, ID0 = 0;
	struct llt_snode * this = NULL;
	if (! llt_sinsert(&head, DT0, ID0)) {
		goto CLEAN_UP;
	}
	this = head;
	printf("Insert: %d-%d\n", ID0, DT0);
	llt_sprint(head);
	assert(this->data == DT0);
	printf("\n");

	// Insert tail (last index).
	const int DT1 = 11, ID1 = MAX_NODE+1;
	if (! llt_sinsert(&head, DT1, ID1)) {
		goto CLEAN_UP;
	}
	this = head;
	while (this->next) {
		this = this->next;
	}
	printf("Insert: %d-%d\n", ID1, DT1);
	llt_sprint(head);
	assert(this->data == DT1);
	printf("\n");

	// Insert tail (overflow index).
	const int DT2 = 23, ID2 = MAX_NODE*2;
	if (! llt_sinsert(&head, DT2, ID2)) {
		goto CLEAN_UP;
	}
	this = head;
	while (this->next) {
		this = this->next;
	}
	printf("Insert: %d-%d\n", ID2, DT2);
	llt_sprint(head);
	assert(this->data == DT2);
	printf("\n");

	// Insert middle.
	const int DT3 = 7, ID3 = MAX_NODE/2;
	if (! llt_sinsert(&head, DT3, ID3)) {
		goto CLEAN_UP;
	}
	this = head;
	for (int i = 0; i < ID3; i++) {
		this = this->next;
	}
	printf("Insert: %d-%d\n", ID3, DT3);
	llt_sprint(head);
	assert(this->data == DT3);
	printf("\n");

	is_ok = true;
CLEAN_UP:
	llt_sfree(&head);
	return is_ok;
}


static bool
zz_llt_sdelete(void) {
	// Create a list.
	struct llt_snode * head = NULL;
	bool is_ok = false;
	if (! zz_slist(&head)) {
		goto CLEAN_UP;
	}
	llt_sprint(head);
	printf("\n");

	// Test a negative index.
	const int ERR = -1;
	if (llt_sdelete(&head, ERR)) {
		assert(false);
	}
	printf("\n");

	// Delete head.
	const int ID0 = 0;
	const int HEAD0 = 43;
	const int TAIL0 = 51;
	struct llt_snode * this = NULL;
	if (! llt_sdelete(&head, ID0)) {
		goto CLEAN_UP;
	}
	printf("Delete: %d\n", ID0);
	llt_sprint(head);
	this = head;
	while (this->next) {
		this = this->next;
	}
	assert(head->data == HEAD0);
	assert(this->data == TAIL0);
	printf("\n");

	// Delete tail (last index).
	const int ID1 = MAX_NODE-2;
	const int HEAD1 = 43;
	const int TAIL1 = 50;
	if (! llt_sdelete(&head, ID1)) {
		goto CLEAN_UP;
	}
	printf("Delete: %d\n", ID1);
	llt_sprint(head);
	this = head;
	while (this->next) {
		this = this->next;
	}
	assert(head->data == HEAD1);
	assert(this->data == TAIL1);
	printf("\n");

	// Delete tail (overflow index).
	const int ID2 = MAX_NODE*2;
	const int HEAD2 = 43;
	const int TAIL2 = 49;
	if (! llt_sdelete(&head, ID2)) {
		goto CLEAN_UP;
	}
	printf("Delete: %d\n", ID2);
	llt_sprint(head);
	this = head;
	while (this->next) {
		this = this->next;
	}
	assert(head->data == HEAD2);
	assert(this->data == TAIL2);
	printf("\n");

	// Delete middle.
	const int ID3 = 2;
	const int HEAD3 = 43;
	// Value of the new node at index 2.
	const int TAIL3 = 46;
	if (! llt_sdelete(&head, ID3)) {
		goto CLEAN_UP;
	}
	printf("Delete: %d\n", ID3);
	llt_sprint(head);
	this = head;
	for (int i = 0; i < ID3; i++) {
		this = this->next;
	}
	assert(head->data == HEAD3);
	assert(this->data == TAIL3);
	printf("\n");

	is_ok = true;
CLEAN_UP:
	llt_sfree(&head);
	return is_ok;
}
// LLT_TEST {{{2

bool
llt_test(void) {
	return zz_llt_sdelete();
//	return zz_llt_sinsert();
//	return zz_llt_sfree();
//	return zz_llt_sprint();
//	return zz_llt_snew();

//	return true;
}


NO_WARNING_END
#endif // DEBUG_LLT
// SLIST {{{1

bool
llt_snew(struct llt_snode ** head) {
	*head = malloc(sizeof(struct llt_snode));
	if (! *head) {
		PRINT_ERROR("Memory error.");
		return false;
	}
	(*head)->data = 0;
	(*head)->next = NULL;
	return true;
}


void
llt_sprint(struct llt_snode * head) {
	struct llt_snode * this = head;
	for (int i = 0; this; i++) {
		printf("%d: %d\n", i, this->data);
		this = this->next;
	}
}


bool
llt_sfree(struct llt_snode ** head) {
	struct llt_snode * this = *head;
	struct llt_snode * child = NULL;
#if DEBUG_LLT
	int i = 0;
#endif
	while (this) {
#if DEBUG_LLT
		printf("Del %d: %d\n", i, this->data);
		i++;
#endif
		child = this->next;
		free(this);
		this = child;
	}
	*head = NULL;
	return true;
}


bool
llt_sinsert(struct llt_snode ** head, int data, int index) {
	if (! *head) {
		PRINT_ERROR("Head is NULL.");
		return false;
	} else if (index < 0) {
		PRINT_ERROR("Index is negative.");
		return false;
	}

	struct llt_snode * node = NULL;
	if (! llt_snew(&node)) {
		PRINT_ERROR("Memory error.");
		free(node);
		return false;
	}

	node->data = data;
	if (index == 0) {
		node->next = *head;
		*head = node;
		return true;
	}

	struct llt_snode * this = *head;
	// New node occupies position `index`.
	for (int i = 0; i < index-1; i++) {
		if (! this->next) {
			break;
		}
		this = this->next;
	}
	node->next = this->next;
	this->next = node;
	return true;
}


bool
llt_sdelete(struct llt_snode ** head, int index) {
	if (! *head) {
		PRINT_ERROR("Head is NULL.");
		return false;
	} else if (index < 0) {
		PRINT_ERROR("Index is negative.");
		return false;
	}

	struct llt_snode * fast = *head;
	if (index == 0) {
		*head = (*head)->next;
		free(fast);
		return true;
	}

	struct llt_snode * slow = *head;
	fast = (*head)->next;
	for (int i = 0; i < index-1; i++) {
		if (! fast->next) {
			break;
		}
		fast = fast->next;
		slow = slow->next;
	}
	slow->next = fast->next;
	free(fast);
	return true;
}
