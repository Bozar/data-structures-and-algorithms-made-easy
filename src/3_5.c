#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"
#include "debug.h"


static struct llt_snode * create_list(void);
static bool free_list(struct llt_snode * head);
static const struct llt_snode * get_tail_node(
		const struct llt_snode * head, int index
);


static struct llt_snode *
create_list(void) {
	struct llt_snode * head = NULL;
	if (! llt_snew(&head)) {
		PRINT_ERROR("Failed: llt_snew().");
		exit(EXIT_FAILURE);
	}
	head->data = 42;
	for (int i = 1; i < 10; i++) {
		if (! llt_sinsert(&head, i+42, i)) {
			PRINT_ERROR("Failed: llt_sinsert().");
			exit(EXIT_FAILURE);
		}
	}
	llt_sprint(head);
	return head;
}


static bool
free_list(struct llt_snode * head) {
	if (! llt_sfree(&head)) {
		PRINT_ERROR("Failed: llt_sfree().");
		return false;
	}
	return true;
}


static const struct llt_snode *
get_tail_node(const struct llt_snode * head, int index) {
	if (head == NULL) {
		PRINT_ERROR("Head is NULL.");
		return NULL;
	} else if (index < 0) {
		PRINT_ERROR("Index is negative.");
		return NULL;
	}

	const struct llt_snode * fast = head;
	const struct llt_snode * slow = head;
	while (fast->next != NULL) {
		fast = fast->next;
		if (index > 0) {
			index -= 1;
		} else {
			slow = slow->next;
		}
	}
	return slow;
}


int
main(void) {
	struct llt_snode * head = create_list();
	const struct llt_snode * this = NULL;

	this = get_tail_node(head, -1);
	assert(this == NULL);

	this = get_tail_node(head, 0);
	assert(this && (this->data == 51));
	printf("%d: %d\n", 0, this->data);

	this = get_tail_node(head, 4);
	assert(this && (this->data == 47));
	printf("%d: %d\n", 4, this->data);

	this = get_tail_node(head, 9);
	assert(this && (this->data == 42));
	printf("%d: %d\n", 9, this->data);

	this = get_tail_node(head, 99);
	assert(this && (this->data == 42));
	printf("%d: %d\n", 99, this->data);

	if (! free_list(head)) {
		exit(EXIT_FAILURE);
	}
	printf("Passed.\n");
	exit(EXIT_SUCCESS);
}
