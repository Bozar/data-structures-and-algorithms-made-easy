#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"
#include "debug.h"
#include "utility.h"


static void create_list(struct llt_cnode ** head);
static void split(
		struct llt_cnode * head,
		struct llt_cnode ** head1, struct llt_cnode ** head2
);


static void
create_list(struct llt_cnode ** head) {
	if (! llt_cnew(head)) {
		PRINT_ERROR("Failed: llt_cnew().");
		exit(EXIT_FAILURE);
	}

	(*head)->data = 42;
	for (int i = 1; i < 6; i++) {
		if (! llt_cinsert(head, i+42, i)) {
			PRINT_ERROR("Failed: llt_sinsert().");
			exit(EXIT_FAILURE);
		}
	}
}


static void
split(
		struct llt_cnode * head,
		struct llt_cnode ** head1, struct llt_cnode ** head2
) {
	struct llt_cnode * fast = head;
	struct llt_cnode * slow = head;
	for (int i = 0; fast->next != head; ) {
		i++;
		fast = fast->next;
		if (i == 2) {
			i = 0;
			slow = slow->next;
		}
	}
	*head1 = head;
	*head2 = slow->next;
	slow->next = *head1;
	fast->next = *head2;
}


int
main(void) {
	printf("Problem: 3.35\n\n");

	struct llt_cnode * head = NULL;
	create_list(&head);
	llt_cprint(head);

	struct llt_cnode * head1 = NULL;
	struct llt_cnode * head2 = NULL;
	int data[] = {42, 43, 44, 45, 46, 47, 48,};
	int data_size = SIZE_ARR(data);

	split(head, &head1, &head2);
	if (head1 == NULL) {
		assert(false);
	}
	printf("\nHead1:\n");
	llt_cprint(head1);
	for (int i = 0; i < 3; i++) {
		assert(head1->data == data[i]);
		head1 = head1->next;
	}
	if (head2 == NULL) {
		assert(false);
	}
	printf("\nHead2:\n");
	llt_cprint(head2);
	for (int i = 3; i < data_size-1; i++) {
		assert(head2->data == data[i]);
		head2 = head2->next;
	}

	printf("\nAdd a node.\n");
	create_list(&head);
	llt_cinsert(&head, 48, 999);
	llt_cprint(head);

	head1 = NULL;
	head2 = NULL;
	split(head, &head1, &head2);
	if (head1 == NULL) {
		assert(false);
	}
	printf("\nHead1:\n");
	llt_cprint(head1);
	for (int i = 0; i < 4; i++) {
		assert(head1->data == data[i]);
		head1 = head1->next;
	}
	if (head2 == NULL) {
		assert(false);
	}
	printf("\nHead2:\n");
	llt_cprint(head2);
	for (int i = 4; i < data_size-1; i++) {
		assert(head2->data == data[i]);
		head2 = head2->next;
	}

	printf("\nPassed.\n");
	exit(EXIT_SUCCESS);
}
