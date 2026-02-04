#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"
#include "utility.h"


static void get_span(const int * data, const int data_size, int * span);
static void get_index(
		const int * data, const int data_size, int * index,
		struct stk_astack * save_index, int cur_index
);


static void
get_span(const int * data, const int data_size, int * span) {
	struct stk_astack * stack = NULL;
	stk_anew(&stack);
	get_index(data, data_size, span, stack, 0);
	for (int i = 0; i < data_size; i++) {
		span[i] = i-span[i];
	}
}


static void
get_index(
		const int * data, const int data_size, int * index,
		struct stk_astack * save_index, int cur_index
) {
	if (cur_index >= data_size) {
		return;
	}

	int top = 0;
	if ((cur_index == 0) || (data[cur_index] <= data[cur_index-1])) {
		index[cur_index] = cur_index-1;
	} else {
		while (! stk_ais_empty(save_index)) {
			stk_apeek(save_index, &top);
			if (data[cur_index] > data[top]) {
				stk_apop(save_index, &top);
			} else {
				break;
			}
		}
		if (stk_ais_empty(save_index)) {
			index[cur_index] = -1;
		} else {
			stk_apeek(save_index, &top);
			index[cur_index] = top;
		}
	}
	stk_apush(save_index, cur_index);
	get_index(data, data_size, index, save_index, cur_index+1);
}


int
main(void) {
	int data[] = {
		2, 3, 7,
		7, 2, 1,
		4, 8, 6,
	};
	int data_size = SIZE_ARR(data);
	int check[] = {
		1, 2, 3,
		1, 1, 1,
		3, 8, 1,
	};
	int span[] = {
		0, 0, 0,
		0, 0, 0,
		0, 0, 0,
	};

	get_span(data, data_size, span);
	for (int i = 0; i < data_size; i++) {
		PRINT_LOG("%d: %d", data[i], span[i]);
		assert(span[i] == check[i]);
	}

	PRINT_LOG("Passed.");
	exit(EXIT_SUCCESS);
}
