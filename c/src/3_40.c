#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"
#include "debug.h"
#include "utility.h"


static int get_leader(int max_n, int elm_m);


static int
get_leader(int max_n, int elm_m) {
	struct llt_cnode * head = NULL;
	llt_cnew(&head);
	head->data = 1;
	for (int i = 1; i < max_n; i++) {
		llt_cinsert(&head, i+1, i);
	}

	struct llt_cnode * this = head;
	for (int i = max_n; i > 1; i--) {
		for (int j = 1; j < elm_m-1; j++) {
			this = this->next;
		}
		this->next = (this->next)->next;
		this = this->next;
	}
	llt_cprint(this);
	return this->data;
}


int
main(void) {
	printf("Problem: 3.40\n\n");

	PRINT_LOG("N: %d, M: %d", 9, 2);
	assert(get_leader(9, 2) == 3);
	printf("\n");

	PRINT_LOG("N: %d, M: %d", 9, 3);
	assert(get_leader(9, 3) == 1);
	printf("\n");

	PRINT_LOG("N: %d, M: %d", 9, 4);
	assert(get_leader(9, 4) == 1);
	printf("\n");

	PRINT_LOG("N: %d, M: %d", 9, 5);
	assert(get_leader(9, 5) == 8);
	printf("\n");

	PRINT_LOG("N: %d, M: %d", 9, 6);
	assert(get_leader(9, 6) == 7);
	printf("\n");

	PRINT_LOG("N: %d, M: %d", 9, 7);
	assert(get_leader(9, 7) == 2);
	printf("\n");

	PRINT_LOG("N: %d, M: %d", 9, 8);
	assert(get_leader(9, 8) == 3);
	printf("\n");

	PRINT_LOG("N: %d, M: %d", 9, 9);
	assert(get_leader(9, 9) == 8);
	printf("\n");

	PRINT_LOG("N: %d, M: %d", 9, 10);
	assert(get_leader(9, 10) == 8);

	printf("\nPassed.\n");
	exit(EXIT_SUCCESS);
}
