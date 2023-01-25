#include "sort.h"

/**
 * counting_sort- sorts an array of integers in ascending
 * order using the Counting sort algorithm
 *
 * @array: The array to sort.
 * @size: The length of the array.
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	unsigned int i;
	int *count, k, j;

	k = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > k)
		{
			k = array[i];
		}
	}

	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
		return;

	for (j = 0; j <= k; i++)
		count[j] = 0;
	for (j = 0; j < 100; j++)
		printf("%d ", count[j]);
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (j = 1; j < k; i++)
	{
		count[j] = count[j] + count[j - 1];
		printf("%d, ", count[j]);
	}
	
	for (i = 0; i < size; i++)
	{
		/** new_array[--count[array[i]]] = array[i]; */
		j = count[array[i]] - 1;
		if (array[i] != array[j])
		{
			k = array[i];
			array[i] = array[j];
			array[j] = k;
		}
	}
	print_array(array, size);
	free(count); 
}
