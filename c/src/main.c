#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "stack.h"
#include "queue.h"
#include "debug.h"


int
main(void) {
#if DEBUG_QUE
	if (que_test()) {
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
#endif

	printf("Is not debug\n");
	exit(EXIT_SUCCESS);
}
