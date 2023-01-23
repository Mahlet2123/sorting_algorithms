#include "sort.h"

/**
 * quick_sort- sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * Return: void
 */ 

void quick_sort(int *array, size_t size)
{
	quicksort_recursion (array, 0, size - 1);
}

void quicksort_recursion (int *array, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition (array, low, high);
		/** left hand portion */
		quicksort_recursion (array, low, pivot_index - 1);
		/** right hand portion */
		quicksort_recursion (array, pivot_index + 1, high);
	}
}

int partition (int *array, int low, int high)
{
	int pivot_value, i = low, j, temp;

	pivot_value = array[high];
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot_value)
		{
			/** swap (array[i], array[j]); */
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
		}
	}
	/** swap (array[i], array[high]); */
	temp = array[i];
	array[i] = array[high];
	array[high] = temp;
	return (i);
}
