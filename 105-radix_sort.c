#include "sort.h"

/**
 * max - function return finding the max number
 *
 * @array: The main array
 *
 * @size: The size of array
 *
 * Return: The max Number
*/

int max(int *array, size_t size)
{
size_t x;
int max_num = array[0];

	for (x = 0; x < size; x++)
	{
		if (array[x] > max_num)
			max_num = array[x];
	}
	return (max_num);
}

/**
 * countingSort_radix - function that making counting sort
 *
 * @array: The main Array
 *
 * @size: the size of array
 *
 * @pass: The pass
 *
 * @sorted: the array sorted
*/

void countingSort_radix(int *array, size_t size, int pass, int *sorted)
{
size_t k = (max(array, size) + 1);
int *count = malloc(k * sizeof(int));
size_t i;

	if (count == NULL)
		return;

	for (i = 0; i < k; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		++count[(array[i] / pass) % 10];

	for (i = 1; i < k; i++)
		count[i] += count[i - 1];

	for (i = (size - 1); i != SIZE_MAX; i--)
		sorted[--count[(array[i] / pass) % 10]] = array[i];

	for (i = 0; i < size; i++)
		array[i] = sorted[i];
	free(count);
}

/**
 * radix_sort -  function makine radix sort
 *
 * @array: The main Array
 *
 * @size: the size of array
*/
void radix_sort(int *array, size_t size)
{
int max_num = max(array, size);
int pass;
int *sorted;

	if (!array || size < 2)
		return;
	sorted = malloc(size * sizeof(int));
	if (sorted == NULL)
		return;

	for (pass = 1; (max_num / pass) >= 1; (pass *= 10))
	{
		countingSort_radix(array, size, pass, sorted);
		print_array(array, size);
	}

	free(sorted);
}
