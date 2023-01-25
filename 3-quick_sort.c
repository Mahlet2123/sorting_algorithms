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
	if (array == NULL || size < 2)
		return;
	quicksort_recursion(array, 0, size - 1, size);
}

/**
 * quicksort_recursion- recursive function
 * @array: The array to be sorted
 * @high: hign index (pivot value)
 * @low: low index
 * @size: Number of elements in @array
 * Return: void
 */
void quicksort_recursion(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		/** left hand portion */
		quicksort_recursion(array, low, pivot_index - 1, size);
		/** right hand portion */
		quicksort_recursion(array, pivot_index + 1, high, size);
	}
}

/**
 * partition- divides the array around pivot value
 * @array: The array to be sorted
 * @high: hign index (pivot value)
 * @low: low index
 * @size: Number of elements in @array
 * Return: int(pivot index)
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot_value, i = low - 1, j, temp;

	pivot_value = array[high];
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot_value)
		{
			i++;
			/** swap (array[i], array[j]); */
			if (i == j)
				continue;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	/** swap (array[i], array[high]); */
	i++;
	if (i != high)
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i);
}
