#include "sort.h"

/**
 * shell_sort - is a sorting algorithm
 *
 * @array: The main unsorted array
 *
 * @size: The size of array
*/

void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && array[j - gap] > array[j]; j -= gap)
				swap(&array[j], &array[j - gap]);
		}
		gap /= 3;
		print_array(array, size);
	}
}

/**
 * swap - function making swap
 *
 * @i: first element
 *
 * @j: second element
*/

void swap(int *i, int *j)
{
	int temp;

	temp = *j;
	*j = *i;
	*i = temp;
}
