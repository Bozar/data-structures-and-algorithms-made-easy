#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"
#include "utility.h"


static int get_max_area(
		const int * data, const int data_size, int * start, int * end
);
static int get_area(
		const int * data, struct stk_astack * stack,
		int * start, int * end
);


static int
get_max_area(const int * data, const int data_size, int * start, int * end) {
	struct stk_astack * stack = NULL;
	if (! stk_anew(&stack)) {
		return 0;
	}

	int max_area = 0, blk_area = 0;
	int blk_start = 0, blk_end = 0;
	stk_apush(stack, 0);
	for (int i = 1; i < data_size; i++) {
		if (stk_ais_empty(stack) || (data[i] >= data[i-1])) {
			stk_apush(stack, i);
			continue;
		}
		blk_area = get_area(data, stack, &blk_start, &blk_end);
		if (blk_area > max_area) {
			max_area = blk_area;
			*start = blk_start;
			*end = blk_end;
		}
	}
	return max_area;
}


static int
get_area(const int * data, struct stk_astack * stack, int * start, int * end) {
	int width = 0, area = 0, top = 0;
	stk_apeek(stack, end);
	top = *end;
	while (! stk_ais_empty(stack)) {
		stk_apop(stack, &top);
		width += 1;
		if (data[top]*width > area) {
			area = data[top]*width;
			*start = top;
		}
	}
	return area;
}


int
main(void) {
	int data[] = {
		3, 2, 5, 6, 1, 4, 4,
	};
	int data_size = SIZE_ARR(data);
	int check[] = {2, 3, 10,};
	int start = 0, end = 0, area = 0;
	int * output[] = {&start, &end, &area,};
	char * label[] = {"Start", "End", "Area",};

	area = get_max_area(data, data_size, &start, &end);
	PRINT_LOG("Start: %d, End: %d, Area: %d", start, end, area);
	for (int i = 0; i < 3; i++) {
		if (*(output[i]) == check[i]) {
			continue;
		}
		PRINT_ERR(
				"Error: %s: %d: %d.",
				label[i], *(output[i]), check[i]
		);
		assert(false);
	}

	PRINT_LOG("Passed.");
	exit(EXIT_SUCCESS);
}
