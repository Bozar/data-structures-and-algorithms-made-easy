#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"


//#define NDEBUG


int
main(void) {
#if ! defined(NDEBUG)
	if (llt_test()) {
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
#endif // NDEBUG

	printf("Is not debug\n");
	exit(EXIT_SUCCESS);
}
