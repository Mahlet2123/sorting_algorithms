#include "sort.h"
/**
*swap - swaps 2 nodes in a doubly-linked list
*@a: address of first node
*@b: address of second node
*
*Return: void
*/
void swap_list(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}
