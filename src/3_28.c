#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"
#include "debug.h"


static void create_list(struct llt_snode ** head);
static void reverse_print(struct llt_snode * head);


static void
create_list(struct llt_snode ** head) {
	if (! llt_snew(head)) {
		PRINT_ERROR("Failed: llt_snew().");
		exit(EXIT_FAILURE);
	}

	(*head)->data = 42;
	for (int i = 1; i < 10; i++) {
		if (! llt_sinsert(head, i+42, i)) {
			PRINT_ERROR("Failed: llt_sinsert().");
			exit(EXIT_FAILURE);
		}
	}
	llt_sprint(*head);
}


static void
reverse_print(struct llt_snode * head) {
	if (head == NULL) {
		return;
	} else if (head->next == NULL) {
		printf("%d\n", head->data);
	} else {
		reverse_print(head->next);
		printf("%d\n", head->data);
	}
}


int
main(void) {
	printf("Problem: 3.28\n\n");

	struct llt_snode * head = NULL;
	create_list(&head);
	printf("\n");
	reverse_print(head);

	printf("\nPassed.\n");
	exit(EXIT_SUCCESS);
}
