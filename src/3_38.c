#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"
#include "debug.h"
#include "utility.h"


static void create_list(struct llt_snode ** head);
static void reverse_list(
		struct llt_snode ** head, struct llt_snode * prev, int k_val
);
static void reverse_block(
		struct llt_snode ** head, struct llt_snode * prev,
		struct llt_snode * tail
);


static void
create_list(struct llt_snode ** head) {
	if (! llt_snew(head)) {
		PRINT_ERROR("Failed: llt_cnew().");
		exit(EXIT_FAILURE);
	}

	(*head)->data = 0;
	for (int i = 1; i < 10; i++) {
		if (! llt_sinsert(head, i, i)) {
			PRINT_ERROR("Failed: llt_sinsert().");
			exit(EXIT_FAILURE);
		}
	}
}


static void
reverse_list(struct llt_snode ** head, struct llt_snode * prev, int k_val) {
	if (*head == NULL) {
		return;
	}

	struct llt_snode * tail = *head;
	for (int i = 1; i < k_val; i++) {
		tail = tail->next;
		if (tail == NULL) {
			return;
		}
	}

	struct llt_snode * new_tail = *head;
	reverse_block(head, prev, tail);
	reverse_list(&(new_tail->next), new_tail, k_val);
}


static void
reverse_block(
		struct llt_snode ** head, struct llt_snode * prev,
		struct llt_snode * tail
) {
	if ((*head == NULL) || (tail == NULL) || (*head == tail)) {
		return;
	}

	struct llt_snode * new_head = (*head)->next;
	(*head)->next = tail->next;
	tail->next = *head;
	*head = tail;
	if (prev != NULL) {
		prev->next = new_head;
	}
	reverse_block(&new_head, prev, tail);
}


int
main(void) {
	printf("Problem: 3.38\n\n");

	struct llt_snode * head = NULL;
	create_list(&head);
	llt_sprint(head);

	int data2[] = {1, 0, 3, 2, 5, 4, 7, 6, 9, 8,};
	int data_size = SIZE_ARR(data2);
	printf("\nK = 2\n");
	create_list(&head);
	reverse_list(&head, NULL, 2);
	if (head == NULL) {
		assert(false);
	}
	llt_sprint(head);
	for (int i = 0; i < data_size; i++) {
		assert(head->data == data2[i]);
		head = head->next;
	}

	int data3[] = {2, 1, 0, 5, 4, 3, 8, 7, 6, 9,};
	data_size = SIZE_ARR(data3);
	printf("\nK = 3\n");
	create_list(&head);
	reverse_list(&head, NULL, 3);
	if (head == NULL) {
		assert(false);
	}
	llt_sprint(head);
	for (int i = 0; i < data_size; i++) {
		assert(head->data == data3[i]);
		head = head->next;
	}

	int data4[] = {3, 2, 1, 0, 7, 6, 5, 4, 8, 9,};
	data_size = SIZE_ARR(data4);
	printf("\nK = 4\n");
	create_list(&head);
	reverse_list(&head, NULL, 4);
	if (head == NULL) {
		assert(false);
	}
	llt_sprint(head);
	for (int i = 0; i < data_size; i++) {
		assert(head->data == data4[i]);
		head = head->next;
	}

	int data5[] = {4, 3, 2, 1, 0, 9, 8, 7, 6, 5,};
	data_size = SIZE_ARR(data5);
	printf("\nK = 5\n");
	create_list(&head);
	reverse_list(&head, NULL, 5);
	if (head == NULL) {
		assert(false);
	}
	llt_sprint(head);
	for (int i = 0; i < data_size; i++) {
		assert(head->data == data5[i]);
		head = head->next;
	}

	int data6[] = {5, 4, 3, 2, 1, 0, 6, 7, 8, 9,};
	data_size = SIZE_ARR(data6);
	printf("\nK = 6\n");
	create_list(&head);
	reverse_list(&head, NULL, 6);
	if (head == NULL) {
		assert(false);
	}
	llt_sprint(head);
	for (int i = 0; i < data_size; i++) {
		assert(head->data == data6[i]);
		head = head->next;
	}

	int data7[] = {6, 5, 4, 3, 2, 1, 0, 7, 8, 9,};
	data_size = SIZE_ARR(data7);
	printf("\nK = 7\n");
	create_list(&head);
	reverse_list(&head, NULL, 7);
	if (head == NULL) {
		assert(false);
	}
	llt_sprint(head);
	for (int i = 0; i < data_size; i++) {
		assert(head->data == data7[i]);
		head = head->next;
	}

	int data8[] = {7, 6, 5, 4, 3, 2, 1, 0, 8, 9,};
	data_size = SIZE_ARR(data8);
	printf("\nK = 8\n");
	create_list(&head);
	reverse_list(&head, NULL, 8);
	if (head == NULL) {
		assert(false);
	}
	llt_sprint(head);
	for (int i = 0; i < data_size; i++) {
		assert(head->data == data8[i]);
		head = head->next;
	}

	int data9[] = {8, 7, 6, 5, 4, 3, 2, 1, 0, 9,};
	data_size = SIZE_ARR(data9);
	printf("\nK = 9\n");
	create_list(&head);
	reverse_list(&head, NULL, 9);
	if (head == NULL) {
		assert(false);
	}
	llt_sprint(head);
	for (int i = 0; i < data_size; i++) {
		assert(head->data == data9[i]);
		head = head->next;
	}

	int data10[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0,};
	data_size = SIZE_ARR(data10);
	printf("\nK = 10\n");
	create_list(&head);
	reverse_list(&head, NULL, 10);
	if (head == NULL) {
		assert(false);
	}
	llt_sprint(head);
	for (int i = 0; i < data_size; i++) {
		assert(head->data == data10[i]);
		head = head->next;
	}

	printf("\nPassed.\n");
	exit(EXIT_SUCCESS);
}
