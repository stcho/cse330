#include <stdlib.h>

typedef struct Queue
{
	struct Qelement *head;
} Queue;

typedef struct Qelement
{
	struct Qelement *next;
	struct Qelement *prev;
	int payout;
} Qelement;

void InitQueue(Queue*);
void AddQueue(Queue*, Qelement*);
Qelement* DelQueue(Queue*);
void RotateQ(Queue*);
void AddToFinal(Qelement*, Qelement*);
Qelement* NewItem();

void InitQueue(Queue *q) {
	q->head = NULL;
	return;
}

struct Qelement* NewItem() 
{
	return (Qelement*) malloc(sizeof(Qelement)); 
}

void AddQueue(Queue *q, Qelement *item)
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

void AddToFinal(Qelement *current, Qelement *item) {
	if(current->next == NULL) {
		current->next = item;
		item->next = NULL; 
		item->prev = current;
	} 
	else {
		AddToFinal(current->next, item);
	}
}

Qelement* DelQueue(Queue *q) {
	if (q->head == NULL) {
		return NULL;
	}
	
	Qelement* deletedItem = q->head;
	q->head->next->prev = NULL;
	q->head = q->head->next;

	deletedItem->next = NULL;
	deletedItem->prev = NULL;

	return deletedItem;
}

void RotateQ(Queue *q) {
	AddQueue(q, DelQueue(q));
	return;
}