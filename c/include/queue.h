// PREPROCESSOR {{{1

#ifndef QUEUE_H
#define QUEUE_H


#include <stdbool.h>

#include "debug.h"


#define INIT_QUEUE_SIZE 8
// DEBUG {{{1

#if DEBUG_QUE

bool que_test(void);

#endif
// LINKED_LIST {{{1

struct que_lqueue {
	struct llt_snode * front;
	struct llt_snode * rear;
	int size;
};

bool que_lnew(struct que_lqueue ** queue);
bool que_lenqueue(struct que_lqueue * queue, int data);
bool que_ldequeue(struct que_lqueue * queue, int * data);
bool que_lpeek(struct que_lqueue * queue, int * data);
bool que_lis_empty(struct que_lqueue * queue);
int que_lsize(struct que_lqueue * queue);
void que_lfree(struct que_lqueue ** queue);
// ARRAY_LIST {{{1

struct que_aqueue {
	int front;
	int size;
	unsigned max_size;
	int * array;
};

bool que_anew(struct que_aqueue ** queue);
bool que_aenqueue(struct que_aqueue * queue, int data);
bool que_adequeue(struct que_aqueue * queue, int * data);
bool que_apeek(struct que_aqueue * queue, int * data);
bool que_ais_empty(struct que_aqueue * queue);
int que_asize(struct que_aqueue * queue);
void que_afree(struct que_aqueue ** queue);
// EOF {{{1

#endif // QUEUE_H
