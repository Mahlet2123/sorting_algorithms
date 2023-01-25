#include "sort.h"

/**
  * shell_sort - A function tat sorts an array usin shell algorithm.
  * @array: The array to sort.
  * @size: The length of the array.
  * Return: Nothing.
  */
void shell_sort(int *array, size_t size)
{
	int temp;
	unsigned int i, j, gap = 0;

	if (array == NULL || size < 1)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap = (gap - 1) / 3)
	{
		for (j = gap; j <= size - 1; j++)
		{
			for (i = j - gap; i <= size; i = i - gap)
			{
				if (array[i] < array[i + gap])
					break;
				temp = array[i];
				array[i] = array[i + gap];
				array[i + gap] = temp;
				}
			}
		}
		print_array(array, size);
	}
}
