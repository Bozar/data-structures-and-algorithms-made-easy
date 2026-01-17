#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"
#include "debug.h"


static struct llt_snode * create_list(bool has_loop);
static bool has_loop(const struct llt_snode * head);


static struct llt_snode *
create_list(bool has_loop) {
	struct llt_snode * head = NULL;
	if (! llt_snew(&head)) {
		PRINT_ERR("Failed: llt_snew().");
		exit(EXIT_FAILURE);
	}
	head->data = 42;
	for (int i = 1; i < 10; i++) {
		if (! llt_sinsert(&head, i+42, i)) {
			PRINT_ERR("Failed: llt_sinsert().");
			exit(EXIT_FAILURE);
		}
	}

	if (! has_loop) {
		llt_sprint(head);
		return head;
	}

	struct llt_snode * loop = NULL;
	struct llt_snode * this = head;
	for (int i = 0; this->next != NULL; i++) {
		if (i == 5) {
			loop = this;
		}
		this = this->next;
	}
	this->next = loop;

	this = head;
	for (int i = 0; i < 16; i++) {
		printf("%d: %d\n", i, this->data);
		this = this->next;
	}
	return head;
}


static bool
has_loop(const struct llt_snode * head) {
	const struct llt_snode * slow = head;
	const struct llt_snode * fast = head;
	while ((slow != NULL) && (fast != NULL) && (fast->next != NULL)) {
		slow = slow->next;
		fast = (fast->next)->next;
		if (slow == fast) {
			return true;
		}
	}
	return false;
}


int
main(void) {
	printf("Problem: 3.9\n");
	struct llt_snode * head = NULL;

	head = create_list(false);
	assert(! has_loop(head));

	printf("\n");
	head = create_list(true);
	assert(has_loop(head));

	printf("\nPassed.\n");
	exit(EXIT_SUCCESS);
}
