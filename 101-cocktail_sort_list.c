#include "sort.h"
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
				print_list(*list);
			}	
		}
		temp = temp->prev;
		while (temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				swap_list(temp->prev, temp);
				swaped = 0;
				print_list(*list);
			}
		}
		temp = 
	}
}
