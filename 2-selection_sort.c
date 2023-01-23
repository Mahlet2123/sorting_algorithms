#include "sort.h"

/**
 * selection_sort- sorts an array of integers in
 * ascending order using the Selection sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int c;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}
		if (min_idx != i)
		{
			c = array[i];
			array[i] = array[min_idx];
			array[min_idx] = c;
			print_array(array, size);
		}
	}
}
