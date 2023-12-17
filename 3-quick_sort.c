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
 * @high: The end of partion and pivot
 *
 * Return: The index of pivot
*/

int quick_partion(int *array, int low, int high)
{
	int pivot, i, j;

	i = low - 1;
	pivot = array[high];

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i + 1], &array[high]);

	return (i + 1);
}

/**
 * quick_sort_partioning - function that making quick sort partion
 *
 * @array: The array
 *
 * @low: The beginning of array
 *
 * @high: The high of array
 *
 * @size: the size of array
*/

void quick_sort_partioning(int *array, int low, int  high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = quick_partion(array, low, high);

		print_array(array, size);

		/*partion the lower part*/
		quick_sort_partioning(array, low, pivot - 1, size);
		/*partion the greater part*/
		quick_sort_partioning(array, pivot + 1, high, size);
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

	low = 0;
	high = size - 1;

	quick_sort_partioning(array, low, high, size);
}
