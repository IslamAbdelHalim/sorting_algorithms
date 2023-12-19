#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int max(int *array, int size)
{
	int i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int *count, *sorted_arr;
	int max_num = max(array, size);
	size_t k = (max_num + 1);

	if (array == NULL || size < 2)
		return;

	count = malloc(sizeof(size_t) * (max_num + 1));
	if (count == NULL)
		return;

	sorted_arr = malloc(sizeof(size_t) * size);
	if (sorted_arr == NULL)
	{
		free(count);
		return;
	}

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 0; i < k; i++)
		count[i] += count[i - 1];
	print_array(count, max_num + 1);

	for (i = 0; i < size; i++)
		sorted_arr[--count[array[i]]] = array[i];

	for (i = 0; i < size; i++)
		array[i] = sorted_arr[i];

	free(sorted_arr);
	free(count);
}
