#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"
#include "debug.h"


static void create_list(struct llt_snode ** head);
static struct llt_snode * get_middle(const struct llt_snode * head);


static void
create_list(struct llt_snode ** head) {
	if (! llt_snew(head)) {
		PRINT_ERR("Failed: llt_snew().");
		exit(EXIT_FAILURE);
	}

	(*head)->data = 42;
	for (int i = 1; i < 10; i++) {
		if (! llt_sinsert(head, i+42, i)) {
			PRINT_ERR("Failed: llt_sinsert().");
			exit(EXIT_FAILURE);
		}
	}
	llt_sprint(*head);
}


static struct llt_snode *
get_middle(const struct llt_snode * head) {
	const struct llt_snode * fast = head;
	const struct llt_snode * slow = head;
	int step = 0;
	while ((fast->next != NULL) && (slow->next != NULL)) {
		fast = fast->next;
		step += 1;
		if (step == 2) {
			step = 0;
			slow = slow->next;
		}
	}
	return slow;
}


int
main(void) {
	printf("Problem: 3.27\n\n");

	struct llt_snode * head = NULL;
	create_list(&head);

	struct llt_snode * middle = head;
	struct llt_snode * this = get_middle(head);
	for (int i = 0; i < 4; i++) {
		middle = middle->next;
	}
	printf("\n");
	if (this != NULL) {
		printf("%d, %d\n", middle->data, this->data);
	} else {
		printf("%d, NULL\n", middle->data);
	}
	assert(this == middle);

	llt_sinsert(&head, 52, 10);
	middle = middle->next;
	this = get_middle(head);
	printf("\n");
	llt_sprint(head);
	printf("\n");
	if (this != NULL) {
		printf("%d, %d\n", middle->data, this->data);
	} else {
		printf("%d, NULL\n", middle->data);
	}
	assert(this == middle);

	printf("\nPassed.\n");
	exit(EXIT_SUCCESS);
}
