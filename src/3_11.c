#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"
#include "debug.h"


static struct llt_snode * create_list(bool has_loop);
static bool get_loop_start(const struct llt_snode * head, int * index);


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
get_loop_start(const struct llt_snode * head, int * index) {
	const struct llt_snode * slow = head;
	const struct llt_snode * fast = head;
	while ((slow != NULL) && (fast != NULL) && (fast->next != NULL)) {
		slow = slow->next;
		fast = (fast->next)->next;
		if (slow == fast) {
			goto HAS_LOOP;
		}
	}
	return false;

HAS_LOOP:
	slow = head;
	for (int i = 0; ; i++) {
		if (slow == fast) {
			*index = i;
			break;
		}
		slow = slow->next;
		fast = fast->next;
	}
	return true;
}


int
main(void) {
	printf("Problem: 3.11\n");
	struct llt_snode * head = NULL;
	int index = -1;
	bool is_ok = false;

	head = create_list(false);
	is_ok = get_loop_start(head, &index);
	printf("Loop start: %d\n", index);
	assert(! is_ok);
	assert(index == -1);

	printf("\n");
	head = create_list(true);
	is_ok = get_loop_start(head, &index);
	printf("Loop start: %d\n", index);
	assert(is_ok);
	assert(index == 5);

	printf("\nPassed.\n");
	exit(EXIT_SUCCESS);
}
