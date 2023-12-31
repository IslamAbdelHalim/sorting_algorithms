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
int max_num = 0;

	if (array == NULL || size == 0)
		return (0);
	max_num = array[0];
	for (x = 1; x < size; x++)
	{
		if (array[x] > max_num)
			max_num = array[x];
	}
	return (max_num);
}

/**
 * counting_sort - function that perform the counting sort algorithm
 * @array: the input array to be sorted
 * @size: size of the array
*/
void counting_sort(int *array, size_t size)
{
size_t y;
int *count, *sorted_arr;
int max_num = max(array, size);
size_t k = max_num + 1;

	if (!array || size < 2)
		return;

	count = malloc(k * sizeof(int));
	if (count == NULL)
		return;

	sorted_arr = malloc(size * sizeof(int));
	if (sorted_arr == NULL)
	{
		free(count);
		return;
	}

	for (y = 0; y < k; y++)
		count[y] = 0;

	for (y = 0; y < size; y++)
		++count[array[y]];

	for (y = 0; y < k; y++)
		count[y] += count[y - 1];

	print_array(count, k);

	for (y = (size - 1); y != SIZE_MAX; y--)
		sorted_arr[--count[array[y]]] = array[y];

	for (y = 0; y < size; y++)
		array[y] = sorted_arr[y];

	free(sorted_arr);
	free(count);
}
