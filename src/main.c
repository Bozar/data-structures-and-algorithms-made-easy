#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "stack.h"
#include "debug.h"


int
main(void) {
#if DEBUG_STK
	if (stk_test()) {
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
#endif

	printf("Is not debug\n");
	exit(EXIT_SUCCESS);
}
