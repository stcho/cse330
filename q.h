#include <stdlib.h>
#include "tcb.h"

typedef struct Queue
{
	struct TCB_t *head;
} Queue;

TCB_t* NewItem();
void InitQueue(Queue*);
void AddQueue(Queue*, TCB_t*);
TCB_t* DelQueue(Queue*);
void RotateQ(Queue*);
void AddToFinal(TCB_t*, TCB_t*);


struct TCB_t* NewItem() 
{
	return (TCB_t*) malloc(sizeof(TCB_t)); 
}

void InitQueue(Queue *q) {
	q->head = NULL;
	return;
}

void AddQueue(Queue *q, TCB_t *item)
{
	if(q->head == NULL) {
		q->head = item;
		q->head->next = NULL;
		q->head->prev = NULL;
	}
	else 	{
		AddToFinal(q->head, item);
	}
}

void AddToFinal(TCB_t *current, TCB_t *item) {
	if(current->next == NULL) {
		current->next = item;
		item->next = NULL; 
		item->prev = current;
	} 
	else {
		AddToFinal(current->next, item);
	}
}
