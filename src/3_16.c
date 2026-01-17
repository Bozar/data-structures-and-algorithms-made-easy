#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"
#include "debug.h"


static struct llt_snode * create_list(int data_arr[]);
static struct llt_snode * reverse_iterative(struct llt_snode * head);
static struct llt_snode * reverse_recursive(struct llt_snode * head);


static struct llt_snode *
create_list(int data_arr[]) {
	struct llt_snode * head = NULL;
	if (! llt_snew(&head)) {
		PRINT_ERR("Failed: llt_snew().");
		exit(EXIT_FAILURE);
	}
	head->data = 42;
	data_arr[0] = 42;
	for (int i = 1; i < 10; i++) {
		if (! llt_sinsert(&head, i+42, i)) {
			PRINT_ERR("Failed: llt_sinsert().");
			exit(EXIT_FAILURE);
		}
		data_arr[i] = i+42;
	}
	llt_sprint(head);
	return head;
}


static struct llt_snode *
reverse_iterative(struct llt_snode * head) {
	struct llt_snode * new_head = NULL;
	struct llt_snode * this = NULL;
	while (head != NULL) {
		this = head->next;
		head->next = new_head;
		new_head = head;
		head = this;
	}
	return new_head;
}


static struct llt_snode *
reverse_recursive(struct llt_snode * head) {
	if (head->next == NULL) {
		return head;
	}

	struct llt_snode * this = head->next;
	head->next = NULL;
	struct llt_snode * new_head = reverse_recursive(this);
	this->next = head;
	return new_head;
}


int
main(void) {
	printf("Problem: 3.16\n\n");

	struct llt_snode * head = NULL;
	struct llt_snode * this = NULL;
	int data_arr[10] = {0};
	head = create_list(data_arr);

	head = reverse_iterative(head);
	this = head;
	printf("\n");
	llt_sprint(head);
	for (int i = 9; i > -1; i--) {
		assert(this->data == data_arr[i]);
		this = this->next;
	}

	head = reverse_recursive(head);
	this = head;
	printf("\n");
	llt_sprint(head);
	for (int i = 0; i < 10; i++) {
		assert(this->data == data_arr[i]);
		this = this->next;
	}

	printf("\nPassed.\n");
	exit(EXIT_SUCCESS);
}
