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
	int *count, *new_array, k, j;

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
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (j = 1; j < k; i++)
	{
		count[j] = count[j] + count[j - 1];
		printf("%d, ", count[j]);
	}
	new_array = malloc(sizeof(int) * size);
	if (new_array == NULL)
		return;
	for (i = size - 1; i > 0; i--)
	{
		new_array[count[array[i] - 1]] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = new_array[i];
	print_array(array, size);
	free(count), free(new_array); 
}
