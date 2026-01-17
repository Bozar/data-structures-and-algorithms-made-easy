#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"
#include "debug.h"
#include "utility.h"


static void create_list(struct llt_snode ** head1, struct llt_snode ** head2);
static struct llt_snode * merge_iterative(
		const struct llt_snode * head1, const struct llt_snode * head2
);
static void merge_recursive(
		const struct llt_snode * head1, const struct llt_snode * head2,
		struct llt_snode ** mhead, struct llt_snode ** mtail
);


static void
create_list(struct llt_snode ** head1, struct llt_snode ** head2) {
	if (! llt_snew(head1)) {
		PRINT_ERR("Failed: llt_snew().");
		exit(EXIT_FAILURE);
	} else if (! llt_snew(head2)) {
		PRINT_ERR("Failed: llt_snew().");
		exit(EXIT_FAILURE);
	}

	(*head1)->data = 0;
	(*head2)->data = 0;
	for (int i = 1; i < 5; i++) {
		if (i < 3) {
			if (! llt_sinsert(head1, i, i)) {
				PRINT_ERR("Failed: llt_sinsert().");
				exit(EXIT_FAILURE);
			}
			if (! llt_sinsert(head2, i+2, i)) {
				PRINT_ERR("Failed: llt_sinsert().");
				exit(EXIT_FAILURE);
			}
		} else {
			if (! llt_sinsert(head1, i+42-3+2, i)) {
				PRINT_ERR("Failed: llt_sinsert().");
				exit(EXIT_FAILURE);
			}
			if (! llt_sinsert(head2, i+42-3, i)) {
				PRINT_ERR("Failed: llt_sinsert().");
				exit(EXIT_FAILURE);
			}
		}
	}
	llt_sprint(*head1);
	printf("\n");
	llt_sprint(*head2);
}


static struct llt_snode *
merge_iterative(
		const struct llt_snode * head1, const struct llt_snode * head2
) {
	struct llt_snode * mhead = NULL;
	struct llt_snode * mtail = NULL;
	struct llt_snode * this = NULL;
	while ((head1 != NULL) || (head2 != NULL)) {
		if (! llt_snew(&this)) {
			return NULL;
		}
		if (head1 == NULL) {
			this->data = head2->data;
			head2 = head2->next;
		} else if (head2 == NULL) {
			this->data = head1->data;
			head1 = head1->next;
		} else if (head1->data > head2->data) {
			this->data = head2->data;
			head2 = head2->next;
		} else {
			this->data = head1->data;
			head1 = head1->next;
		}
		if (mhead == NULL) {
			mhead = this;
			mtail = this;
		} else {
			mtail->next = this;
			mtail = mtail->next;
		}
	}
	return mhead;
}


static void
merge_recursive(
		const struct llt_snode * head1, const struct llt_snode * head2,
		struct llt_snode ** mhead, struct llt_snode ** mtail
) {
	struct llt_snode * this = NULL;
	if ((head1 == NULL) && (head2 == NULL)) {
		return;
	} else if (! llt_snew(&this)) {
		return;
	}

	if (head1 == NULL) {
		this->data = head2->data;
		head2 = head2->next;
	} else if (head2 == NULL) {
		this->data = head1->data;
		head1 = head1->next;
	} else if (head1->data > head2->data) {
		this->data = head2->data;
		head2 = head2->next;
	} else {
		this->data = head1->data;
		head1 = head1->next;
	}
	if (*mhead == NULL) {
		*mhead = this;
		*mtail = this;
	} else {
		(*mtail)->next = this;
		*mtail = (*mtail)->next;
	}
	merge_recursive(head1, head2, mhead, mtail);
}


int
main(void) {
	printf("Problem: 3.31\n\n");

	struct llt_snode * head1 = NULL;
	struct llt_snode * head2 = NULL;
	create_list(&head1, &head2);

	struct llt_snode * merge = NULL;
	const int data[] = {0, 0, 1, 2, 3, 4, 42, 43, 44, 45,};
	const int data_size = SIZE_ARR(data);

	merge = merge_iterative(head1, head2);
	if (merge == NULL) {
		assert(false);
	}
	printf("\n");
	llt_sprint(merge);
	for (int i = 0; i < data_size; i++) {
		assert(merge->data == data[i]);
		merge = merge->next;
	}

	struct llt_snode * mtail = NULL;
	merge = NULL;
	merge_recursive(head1, head2, &merge, &mtail);
	if (merge == NULL) {
		assert(false);
	}
	printf("\n");
	llt_sprint(merge);
	for (int i = 0; i < data_size; i++) {
		assert(merge->data == data[i]);
		merge = merge->next;
	}

	printf("\nPassed.\n");
	exit(EXIT_SUCCESS);
}
