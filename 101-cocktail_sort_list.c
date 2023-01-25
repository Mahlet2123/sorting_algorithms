#include "sort.h"

/**
 *swap_list - swaps 2 nodes in a doubly-linked list
 *@a: address of first node
 *@b: address of second node
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

/**
 * cocktail_sort_list- sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: doubly linked list
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp;
	int swaped;

	if (list == NULL || (*list) == NULL)
		return;
	temp = (*list);
	swaped = 1;
	while (swaped)
	{
		while (temp->next)
		{
			if (temp->n > temp->next->n)
			{
				swap_list(temp, temp->next);
				swaped = 0;
				if (temp->prev->prev == NULL)
					*list = temp->prev;
				print_list(*list);
			}	
		}
		if ((swaped = 1))
			break;
		while (temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				swap_list(temp->prev, temp);
				swaped = 0;
				if (temp->prev == NULL)
					*list = temp;
				print_list(*list);
			}
		}
		if ((swaped = 1))
			break;
	}
}
