#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "debug.h"


int
main(void) {
#if defined(DEBUG_LLT)
	if (llt_test()) {
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
#endif

	printf("Is not debug\n");
	exit(EXIT_SUCCESS);
}
