#include "sort.h"

/**
 * bubble_sort- sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int c, swap;

	for (i = 0; i < size; i++)
	{
		swap = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				c = array[j];
				array[j] = array[j + 1];
				array[j + 1] = c;
				swap = 1;
				print_array(array, size);
			}
		}
		if (swap == 0)
			break;
	}
}
