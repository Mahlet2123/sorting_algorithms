#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp1, *temp2;

	if (list == NULL || (*list) == NULL)
		return;
	temp1 = (*list)->next;
	while (temp1 != NULL)
	{
		current = temp1;
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				/** swap(current & current->prev) */
				temp2 = current->prev;
				temp2->next = current->next;
				if (temp2->next != NULL)
					current->next->prev = temp2;
				current->next = temp2;
				if (temp2->prev != NULL)
					temp2->prev->next = current;
				current->prev = temp2->prev;
				temp2->prev = current;

				if (current->prev == NULL)
					*list = current;
				/** print list */
				print_list(*list);
				continue;
			}
			current = current->prev;
		}
		temp1 = temp1->next;
	}
}
