// PREPROCESSOR {{{1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"
#include "linked_list.h"
// DEBUG {{{1
// MARCO {{{2

#if DEBUG_QUE
NO_WARNING_BEGIN
NO_WARNING(-Wunused-function)
// ZZ_QUE_LINKED_LIST {{{2

// new(), is_empty(), size(), free()
static bool zz_que_lnew(struct que_lqueue ** queue);
static bool zz_que_loperate(void);


static bool
zz_que_lnew(struct que_lqueue ** queue) {
	if (! que_lnew(queue)) {
		PRINT_ERR("Failed: que_lnew()");
		assert(false);
	} else if (! que_lis_empty(*queue)) {
		PRINT_ERR("Failed: que_lis_empty()");
		assert(false);
	} else if (que_lsize(*queue) != 0) {
		PRINT_ERR("Failed: que_lsize()");
		assert(false);
	}
	que_lfree(queue);
	if (*queue != NULL) {
		PRINT_ERR("Failed: que_lfree()");
		assert(false);
	}
	PRINT_LOG("Passed.");
	return true;
}


static bool
zz_que_loperate(void) {
	struct que_lqueue * queue = NULL;
	bool is_ok = false;
	if (! que_lnew(&queue)) {
		PRINT_ERR("Failed: que_lnew()");
		goto CLEAN_UP;
	}

	int data = -1;
	const int front = 0;
	const int rear = 8;
	for (int i = front; i < rear+1; i++) {
		if (! que_lenqueue(queue, i)) {
			PRINT_ERR("Failed: que_lenqueue()");
			goto CLEAN_UP;
		} else if (que_lis_empty(queue)) {
			PRINT_ERR("Failed: que_lis_empty()");
			goto CLEAN_UP;
		} else if (que_lsize(queue) != i+1) {
			PRINT_ERR("Failed: que_lsize()");
			goto CLEAN_UP;
		}
		data = -1;
		if ((! que_lpeek(queue, &data)) || (data != front)) {
			PRINT_ERR("Failed: que_lpeek()");
			goto CLEAN_UP;
		}
	}

	for (int i = rear; i > front; i--) {
		data = -1;
		if ((! que_ldequeue(queue, &data)) || (data != rear-i)) {
			PRINT_ERR("Failed: que_ldequeue()");
			goto CLEAN_UP;
		} else if (que_lis_empty(queue)) {
			PRINT_ERR("Failed: que_lis_empty()");
			goto CLEAN_UP;
		} else if (que_lsize(queue) != i) {
			PRINT_ERR("Failed: que_lsize()");
			goto CLEAN_UP;
		}
		data = -1;
		if ((! que_lpeek(queue, &data)) || (data != rear-i+1)) {
			PRINT_ERR("Failed: que_lpeek()");
			goto CLEAN_UP;
		}
	}
	data = -1;
	if ((! que_ldequeue(queue, &data)) || (data != rear)) {
		PRINT_ERR("Failed: que_ldequeue()");
		goto CLEAN_UP;
	}

	if (que_ldequeue(queue, &data)) {
		PRINT_ERR("Failed: que_ldequeue()");
		goto CLEAN_UP;
	} else if (! que_lis_empty(queue)) {
		PRINT_ERR("Failed: que_lis_empty()");
		goto CLEAN_UP;
	} else if (que_lsize(queue) != 0) {
		PRINT_ERR("Failed: que_lsize()");
		goto CLEAN_UP;
	} else if (que_lpeek(queue, &data)) {
		PRINT_ERR("Failed: que_lpeek()");
		goto CLEAN_UP;
	}

	is_ok = true;
CLEAN_UP:
	que_lfree(&queue);
	if (is_ok) {
		PRINT_LOG("Passed.");
	}
	return is_ok;
}
// ZZ_QUE_ARRAY {{{2

// new(), is_empty(), size(), free()
static bool zz_que_anew(struct que_aqueue ** queue);
//static bool zz_que_aoperate(void);


static bool
zz_que_anew(struct que_aqueue ** queue) {
	if (! que_anew(queue)) {
		PRINT_ERR("Failed: que_anew()");
		assert(false);
	} else if (! que_ais_empty(*queue)) {
		PRINT_ERR("Failed: que_ais_empty()");
		assert(false);
	} else if (que_asize(*queue) != 0) {
		PRINT_ERR("Failed: que_asize()");
		assert(false);
	}
	que_afree(queue);
	if (*queue != NULL) {
		PRINT_ERR("Failed: que_afree()");
		assert(false);
	}
	PRINT_LOG("Passed.");
	return true;
}


//static bool
//zz_que_aoperate(void) {
//	struct que_aqueue * queue = NULL;
//	bool is_ok = false;
//	if (! que_anew(&queue)) {
//		PRINT_ERR("Failed: que_anew()");
//		goto CLEAN_UP;
//	}
//
//	int data = -1;
//	for (int i = 0; i < 9; i++) {
//		if (! que_aenqueue(queue, i)) {
//			PRINT_ERR("Failed: que_aenqueue()");
//			goto CLEAN_UP;
//		} else if (que_ais_empty(queue)) {
//			PRINT_ERR("Failed: que_ais_empty()");
//			goto CLEAN_UP;
//		} else if (que_asize(queue) != i+1) {
//			PRINT_ERR("Failed: que_asize()");
//			goto CLEAN_UP;
//		}
//		data = -1;
//		if ((! que_apeek(queue, &data)) || (data != i)) {
//			PRINT_ERR("Failed: que_apeek()");
//			goto CLEAN_UP;
//		}
//	}
//
//	for (int i = 8; i > 0; i--) {
//		data = -1;
//		if ((! que_adequeue(queue, &data)) || (data != i)) {
//			PRINT_ERR("Failed: que_adequeue()");
//			goto CLEAN_UP;
//		} else if (que_ais_empty(queue)) {
//			PRINT_ERR("Failed: que_ais_empty()");
//			goto CLEAN_UP;
//		} else if (que_asize(queue) != i) {
//			PRINT_ERR("Failed: que_asize()");
//			goto CLEAN_UP;
//		}
//		data = -1;
//		if ((! que_apeek(queue, &data)) || (data != i-1)) {
//			PRINT_ERR("Failed: que_apeek()");
//			goto CLEAN_UP;
//		}
//	}
//	data = -1;
//	if ((! que_adequeue(queue, &data)) || (data != 0)) {
//		PRINT_ERR("Failed: que_adequeue()");
//		goto CLEAN_UP;
//	}
//
//	if (que_adequeue(queue, &data)) {
//		PRINT_ERR("Failed: que_adequeue()");
//		goto CLEAN_UP;
//	} else if (! que_ais_empty(queue)) {
//		PRINT_ERR("Failed: que_ais_empty()");
//		goto CLEAN_UP;
//	} else if (que_asize(queue) != 0) {
//		PRINT_ERR("Failed: que_asize()");
//		goto CLEAN_UP;
//	} else if (que_apeek(queue, &data)) {
//		PRINT_ERR("Failed: que_apeek()");
//		goto CLEAN_UP;
//	}
//
//	is_ok = true;
//CLEAN_UP:
//	que_afree(&queue);
//	if (is_ok) {
//		PRINT_LOG("Passed.");
//	}
//	return is_ok;
//}
// QUE_TEST {{{2

bool
que_test(void) {
	struct que_aqueue * queue = NULL;
	return zz_que_anew(&queue);
//	return zz_que_aoperate();

//	struct que_lqueue * queue = NULL;
//	return zz_que_lnew(&queue);
//	return zz_que_loperate();
}

NO_WARNING_END
#endif // DEBUG_QUE
// LINKED_LIST {{{1

bool
que_lnew(struct que_lqueue ** queue) {
	*queue = malloc(sizeof(struct que_lqueue));
	if (*queue == NULL) {
		PRINT_ERR("Memory error.");
		return false;
	}
	(*queue)->front = NULL;
	(*queue)->rear = NULL;
	(*queue)->size = 0;
	return true;
}


bool
que_lis_empty(struct que_lqueue * queue) {
	if (queue == NULL) {
		PRINT_ERR("Queue is null.");
		return false;
	}

	bool no_front = (queue->front == NULL);
	bool no_size = (queue->size == 0);
	if (no_front && no_size) {
		return true;
	} else if (no_front ^ no_size) {
		PRINT_ERR("No front: %d, no size: %d", no_front, no_size);
	}
	return false;
}


int
que_lsize(struct que_lqueue * queue) {
	if (queue == NULL) {
		PRINT_ERR("Queue is null.");
		return -1;
	}
	return queue->size;
}


void
que_lfree(struct que_lqueue ** queue) {
	if (*queue == NULL) {
		return;
	}

	if ((*queue)->front != NULL) {
		llt_sfree(&((*queue)->front));
		(*queue)->front = NULL;
	}
	if ((*queue)->rear != NULL) {
		llt_sfree(&((*queue)->rear));
		(*queue)->rear = NULL;
	}
	free(*queue);
	*queue = NULL;
}


bool
que_lenqueue(struct que_lqueue * queue, int data) {
	struct llt_snode * node = NULL;
	if (queue == NULL) {
		PRINT_ERR("Queue is null.");
		return false;
	} else if (! llt_snew(&node)) {
		return false;
	}

	node->data = data;
	if (que_lis_empty(queue)) {
		queue->front = node;
		queue->rear = node;
	} else {
		(queue->rear)->next = node;
		queue->rear = node;
	}
	queue->size += 1;
	return true;
}


bool
que_ldequeue(struct que_lqueue * queue, int * data) {
	if (queue == NULL) {
		PRINT_ERR("Queue is null.");
		return false;
	} else if (queue->front == NULL) {
		return false;
	}

	*data = (queue->front)->data;
	queue->front = (queue->front)->next;
	queue->size -= 1;
	return true;
}


bool
que_lpeek(struct que_lqueue * queue, int * data) {
	if (queue == NULL) {
		PRINT_ERR("Queue is null.");
		return false;
	} else if (queue->front == NULL) {
		return false;
	}

	*data = (queue->front)->data;
	return true;
}
// ARRAY {{{1

bool
que_anew(struct que_aqueue ** queue) {
	*queue = malloc(sizeof(struct que_aqueue));
	if (*queue == NULL) {
		PRINT_ERR("Memory error.");
		return false;
	}
	(*queue)->array = malloc(sizeof(int)*INIT_QUEUE_SIZE);
	if ((*queue)->array == NULL) {
		PRINT_ERR("Memory error.");
		return false;
	}
	(*queue)->front = -1;
	(*queue)->size = 0;
	(*queue)->max_size = INIT_QUEUE_SIZE;
	return true;
}


bool
que_ais_empty(struct que_aqueue * queue) {
	if (queue == NULL) {
		PRINT_ERR("Queue is null.");
		return false;
	}

	bool no_front = (queue->front < 0);
	bool no_size = (queue->size == 0);
	if (no_front && no_size) {
		return true;
	} else if (no_front ^ no_size) {
		PRINT_ERR("No front: %d, no size: %d", no_front, no_size);
	}
	return false;
}


int
que_asize(struct que_aqueue * queue) {
	if (queue == NULL) {
		PRINT_ERR("Queue is null.");
		return -1;
	}
	return queue->size;
}


void
que_afree(struct que_aqueue ** queue) {
	if (*queue == NULL) {
		return;
	}

	if ((*queue)->array != NULL) {
		free((*queue)->array);
		(*queue)->array = NULL;
	}
	free(*queue);
	*queue = NULL;
}


//bool
//que_aenqueue(struct que_aqueue * queue, int data) {
//	if (queue == NULL) {
//		PRINT_ERR("Queue is null.");
//		return false;
//	}
//
//	int * new_array = NULL;
//	if ((queue->top)+1 >= (int)queue->max_size) {
//		new_array = realloc(
//				queue->array, sizeof(int)*(queue->max_size)*2
//		);
//		if (new_array == NULL) {
//			PRINT_ERR("Memory error.");
//			return false;
//		}
//		queue->max_size *= 2;
//		queue->array = new_array;
//	} else if (queue->array == NULL) {
//		PRINT_ERR("Array is NULL.");
//		return false;
//	}
//
//	queue->top += 1;
//	(queue->array)[queue->top] = data;
//	return true;
//}
//
//
//bool
//que_adequeue(struct que_aqueue * queue, int * data) {
//	if (queue == NULL) {
//		PRINT_ERR("Queue is null.");
//		return false;
//	} else if (queue->array == NULL) {
//		PRINT_ERR("Array is NULL.");
//		return false;
//	} else if (queue->top < 0) {
//		return false;
//	}
//
//	*data = (queue->array)[queue->top];
//	(queue->array)[queue->top] = 0;
//	queue->top -= 1;
//	return true;
//}
//
//
//bool
//que_apeek(struct que_aqueue * queue, int * data) {
//	if (queue == NULL) {
//		PRINT_ERR("Queue is null.");
//		return false;
//	} else if (queue->array == NULL) {
//		PRINT_ERR("Array is NULL.");
//		return false;
//	} else if ((queue->top < 0) || (queue->top+1 > (int)queue->max_size)) {
//		return false;
//	}
//
//	*data = (queue->array)[queue->top];
//	return true;
//}
