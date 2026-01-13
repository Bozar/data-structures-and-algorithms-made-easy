#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"
#include "debug.h"


static void create_list(struct llt_snode ** head1, struct llt_snode ** head2);
static int get_len(const struct llt_snode *head);
static struct llt_snode * get_merge_point(
		struct llt_snode * head1, struct llt_snode * head2
);


static void
create_list(struct llt_snode ** head1, struct llt_snode ** head2) {
	if (! llt_snew(head1)) {
		PRINT_ERROR("Failed: llt_snew().");
		exit(EXIT_FAILURE);
	}
	else if (! llt_snew(head2)) {
		PRINT_ERROR("Failed: llt_snew().");
		exit(EXIT_FAILURE);
	}

	(*head1)->data = 42;
	(*head2)->data = 42;
	for (int i = 1; i < 10; i++) {
		if (! llt_sinsert(head1, i+42, i)) {
			PRINT_ERROR("Failed: llt_sinsert().");
			exit(EXIT_FAILURE);
		}
		if (i > 2) {
			continue;
		}
		if (! llt_sinsert(head2, i+42, i)) {
			PRINT_ERROR("Failed: llt_sinsert().");
			exit(EXIT_FAILURE);
		}
	}

	struct llt_snode * this1 = *head1;
	struct llt_snode * this2 = *head2;
	for (int i = 0; i < 5; i++) {
		this1 = this1->next;
	}
	while (this2->next != NULL) {
		this2 = this2->next;
	}
	this2->next = this1;

	llt_sprint(*head1);
	printf("\n");
	llt_sprint(*head2);
}


static int
get_len(const struct llt_snode *head) {
	int len = 0;
	while (head != NULL) {
		len++;
		head = head->next;
	}
	return len;
}


static struct llt_snode *
get_merge_point(struct llt_snode * head1, struct llt_snode * head2) {
	int len1 = get_len(head1);
	int len2 = get_len(head2);
	int step = 0;
	struct llt_snode * fast = NULL;
	struct llt_snode * slow = NULL;
	if (len1 > len2) {
		step = len1 - len2;
		fast = head1;
		slow = head2;
	} else {
		step = len2 - len1;
		fast = head2;
		slow = head1;
	}

	for (; step > 0; step--) {
		fast = fast->next;
	}
	while ((fast != NULL) && (slow != NULL)) {
		if (fast == slow) {
			return fast;
		}
		fast = fast->next;
		slow = slow->next;
	}
	return NULL;
}


int
main(void) {
	printf("Problem: 3.23\n\n");

	struct llt_snode * head1 = NULL;
	struct llt_snode * head2 = NULL;
	create_list(&head1, &head2);

	struct llt_snode * this1 = head1;
	struct llt_snode * merge = get_merge_point(head1, head2);
	for (int i = 0; i < 5; i++) {
		this1 = this1->next;
	}
	printf("\n");
	if (merge != NULL) {
		printf("Merge: %d\n", merge->data);
	} else {
		printf("Merge: NULL\n");
	}
	assert(merge == this1);

	printf("\nPassed.\n");
	exit(EXIT_SUCCESS);
}
