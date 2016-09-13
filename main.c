#include <stdio.h>
#include "testq.h"

int main()
{
	Queue *q;
	InitQueue(q);	
	Qelement *a = NewItem();
	a->payout = 1;
	Qelement *b = NewItem();
	b->payout = 2;
	Qelement *c = NewItem();
	c->payout = 3;
	Qelement *d = NewItem();
	d->payout = 4;
	AddQueue(q, a);
	AddQueue(q, b);
	AddQueue(q, c);
	AddQueue(q, d);

	if(a->next->payout == b->payout) {
		printf("a.next = a IS GOOD \n" );
	} else {
		printf("a.next = a IS WRONG \n" );
	}
	if(a->prev == NULL) {
		printf("a.prev = a IS GOOD \n" );
	} else {
		printf("a.prev = a IS WRONG \n" );
	}
	if(b->next->payout == c->payout) {
		printf("b.next = a IS GOOD \n" );
	} else {
		printf("b.next = a IS WRONG \n" );
	}
	if(b->prev->payout == a->payout) {
		printf("b.prev = a IS GOOD \n" );
	} else {
		printf("b.prev = a IS WRONG \n" );
	}
	if(c->next->payout == d->payout) {
		printf("c.next = a IS GOOD \n" );
	} else {
		printf("c.next = a IS WRONG \n" );
	}
	if(c->prev->payout == b->payout) {
		printf("c.prev = a IS GOOD \n" );
	} else {
		printf("c.prev = a IS WRONG \n" );
	}
	if(d->next == NULL) {
		printf("d.next = a IS GOOD \n" );
	} else {
		printf("d.next = a IS WRONG \n" );
	}
	if(d->prev->payout == c->payout) {
		printf("d.prev = a IS GOOD \n" );
	} else {
		printf("d.prev = a IS WRONG \n" );
	}

	Qelement* item1 = DelQueue(q);
	Qelement* item2 = DelQueue(q);
	if(q->head->payout == c->payout) {
		printf("DelQueue a IS GOOD \n" );
	} else {
		printf("DelQueue a IS WRONG \n" );
	}	
	if(q->head->prev == NULL) {
		printf("DelQueue prev a IS GOOD \n" );
	} else {
		printf("DelQueue prev a IS WRONG \n" );
	}	
	if(c->prev == NULL) {
		printf("b prev a IS GOOD \n" );
	} else {
		printf("b prev a IS WRONG \n" );
	}	


	return 0;
}