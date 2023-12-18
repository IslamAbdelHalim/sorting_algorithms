#include "sort.h"

/**
 * swap - function making a swap
 *
 * @i: first element
 *
 * @j: second elemetn
*/

void swap(int *i, int *j)
{
	int temp = *i;

	*i = *j;
	*j = temp;
}
/**
 * quick_partion - function that that compare
 * and return the index of divide the partion
 *
 * @array: array
 *
 * @low: The beginning of new partion
 *
 * @high: The end of partion and pivoti
 *
 * @size: The size of array
 *
 * Return: The index of pivot
*/

void quick_sort_partion(int *array, int low, int high, size_t size)
{
	int pivot, i, j, pivot_idx;

	if (low < high)
	{
		i = low - 1;
		pivot = array[high];

		for (j = low; j < high; j++)
		{
			if (array[j] <= pivot)
			{
				i++;
				swap(&array[j], &array[i]);
				print_array(array, size);
			}
		}

		swap(&array[i + 1], &array[high]);
		print_array(array, size);

		pivot_idx = i + 1;

		quick_sort_partion(array, low, (pivot_idx - 1), size);
		quick_sort_partion(array, (pivot_idx + 1), high, size);
	}
}

/**
 * quick_sort - function that making quick sort
 *
 * @array: The array that making sort
 *
 * @size: the size of array
*/

void quick_sort(int *array, size_t size)
{
	int low, high;

	if (array == NULL || size < 2)
		return;

	low = 0;
	high = size - 1;

	quick_sort_partion(array, low, high, size);
}
