#include "sort.h"
/**
 * max - function that get the maximum number of an array
 * @array: input array to get max from it
 * @size: the length of the array
 * Return: max number
*/
int max(int *array, size_t size)
{
size_t x;
int max_num = array[0];

	for (x = 1; x < size; x++)
	{
		if (array[x] > max_num)
			max_num = array[x];
	}
	return (max_num);
}

/**
 * countingSort_radix - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void countingSort_radix(int *array, size_t size, int pass, int *sorted)
{
	size_t k = max(array, size);
	int *count = malloc(k * sizeof(size_t));
	size_t i;

	for (i = 0; i <= k; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		++count[(array[i] / pass) % 10];

	for (i = 1; i <= k; i++)
		count[i] += count[i - 1];

	for (i = (size - 1); i != SIZE_MAX; i--)
	{
		sorted[--count[(array[i] / pass) % 10]]= array[i];
	}

	for (i = 0; i < size; i++)
		array[i] = sorted[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max_num = max(array, size);
	int pass;
	int *sorted = malloc(size * sizeof(int));

	if (array == NULL || size < 2 || sorted == NULL)
	{
		free(sorted);
		return;
	}

	for (pass = 1; (max_num / pass) > 0; (pass *= 10))
	{
		countingSort_radix(array, size, pass, sorted);
		print_array(array, size);
	}

	free(sorted);
}
