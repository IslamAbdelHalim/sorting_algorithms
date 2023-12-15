#include "sort.h"
/**
 * selection_sort - function that sorts
 *	an array of integers in ascending order.
 *
 * @array: the input array to be sorted.
 * @size: size of the array.
*/
void selection_sort(int *array, size_t size)
{
size_t i, x, min_index;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < (size - 1); i++)
	{
		min_index = i;
		for (x = (i + 1); x < size; x++)
		{
			if (array[x] < array[min_index])
				min_index = x;
		}
		if (min_index != i)
		{
			swap(&array[i], &array[min_index]);
			print_array(array, size);
		}
	}
}

/**
 * swap - function to swap two integers
 *
 * @a: integer one.
 * @b: integer two
*/

void swap(int *a, int *b)
{
int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
