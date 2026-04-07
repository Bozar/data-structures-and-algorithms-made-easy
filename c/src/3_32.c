#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"
#include "debug.h"
#include "utility.h"


static void create_list(struct llt_snode ** head);
static struct llt_snode * reverse_rc(
		struct llt_snode * head, struct llt_snode * prev_node
);
static struct llt_snode * reverse_it(struct llt_snode * head);


static void
create_list(struct llt_snode ** head) {
	if (! llt_snew(head)) {
		PRINT_ERR("Failed: llt_snew().");
		exit(EXIT_FAILURE);
	}

	(*head)->data = 42;
	for (int i = 1; i < 6; i++) {
		if (! llt_sinsert(head, i+42, i)) {
			PRINT_ERR("Failed: llt_sinsert().");
			exit(EXIT_FAILURE);
		}
	}
	llt_sprint(*head);
}


static struct llt_snode *
reverse_rc(struct llt_snode * head, struct llt_snode * prev_node) {
	if ((head == NULL) || (head->next == NULL)) {
		return head;
	}
	struct llt_snode * node0 = head;
	struct llt_snode * node1 = head->next;
	struct llt_snode * node2 = (head->next)->next;
	node0->next = node2;
	node1->next = node0;
	if (prev_node != NULL) {
		prev_node->next = node1;
	}
	reverse_rc(node2, node0);
	return node1;
}


static struct llt_snode *
reverse_it(struct llt_snode * head) {
	if ((head == NULL) || (head->next == NULL)) {
		return head;
	}
	struct llt_snode * prev = NULL;
	struct llt_snode * node0 = head;
	struct llt_snode * node1 = head->next;
	head = head->next;
	while (node1 != NULL) {
		if (prev == NULL) {
			prev = node0;
		} else {
			prev->next = node1;
			prev = node0;
		}
		node0->next = node1->next;
		node1->next = node0;
		node0 = node0->next;
		if (node0 != NULL) {
			node1 = node0->next;
		} else {
			node1 = NULL;
		}
	}
	return head;
}


int
main(void) {
	printf("Problem: 3.32\n\n");

	struct llt_snode * head = NULL;
	struct llt_snode * this = NULL;
	create_list(&head);

	int data1[] = {43, 42, 45, 44, 47, 46, 48,};
	int data2[] = {42, 43, 44, 45, 46, 47, 48,};
	int size = SIZE_ARR(data1);

	head = reverse_rc(head, NULL);
	this = head;
	printf("\nReverse 1:\n");
	llt_sprint(this);
	for (int i = 0; i < size-1; i++) {
		assert(this->data == data1[i]);
		this = this->next;
	}

	head = reverse_it(head);
	this = head;
	printf("\nReverse 2:\n");
	llt_sprint(this);
	for (int i = 0; i < size-1; i++) {
		assert(this->data == data2[i]);
		this = this->next;
	}

	llt_sinsert(&head, 48, 999);
	printf("\nAdd a node.\n");
	llt_sprint(head);

	head = reverse_rc(head, NULL);
	this = head;
	printf("\nReverse 3:\n");
	llt_sprint(this);
	for (int i = 0; i < size; i++) {
		assert(this->data == data1[i]);
		this = this->next;
	}

	head = reverse_it(head);
	this = head;
	printf("\nReverse 4:\n");
	llt_sprint(this);
	for (int i = 0; i < size; i++) {
		assert(this->data == data2[i]);
		this = this->next;
	}

	printf("\nPassed.\n");
	exit(EXIT_SUCCESS);
}
