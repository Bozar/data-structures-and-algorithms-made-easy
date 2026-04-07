#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "utility.h"
#include "linked_list.h"
#include "stack.h"


static void replace(int * input, int size);


static void
replace(int * input, int size) {
	struct stk_astack * stack = NULL;
	stk_anew(&stack);

	int top = -1;
	for (int i = 0; i < size; i++) {
		if (stk_ais_empty(stack)) {
			stk_apush(stack, i);
			continue;
		}
		stk_apeek(stack, &top);
		if (input[top] >= input[i]) {
			stk_apush(stack, i);
			continue;
		}
		while (! stk_ais_empty(stack)) {
			stk_apeek(stack, &top);
			if (input[top] >= input[i]) {
				stk_apush(stack, i);
				break;
			}
			stk_apop(stack, &top);
			input[top] = input[i];
		}
		if (stk_ais_empty(stack)) {
			stk_apush(stack, i);
		}
	}
}


int
main(void) {
	int input[] = {
		3, 4, 4, 7, 2, 5, 6, 8, 7,
	};
	int output[] = {
		4, 7, 7, 8, 5, 6, 8, 8, 7,
	};
	int size = SIZE_ARR(input);

	printf("input: ");
	for (int i = 0; i < size; i++) {
		printf("%d, ", input[i]);
	}
	printf("\n");
	replace(input, size);

	printf("output: ");
	for (int i = 0; i < size; i++) {
		printf("%d, ", input[i]);
		if (input[i] != output[i]) {
			PRINT_ERR("%d: %d-%d", i, input[i], output[i]);
			printf("\n");
			exit(EXIT_FAILURE);
		}
	}
	printf("\n");
	PRINT_LOG("Passed.");
	exit(EXIT_SUCCESS);
}
