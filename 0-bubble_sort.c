#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integers in ascending order.
 *
 * @array: the input array that be sorted.
 * @size: size of the input array.
*/
void bubble_sort(int *array, size_t size)
{
size_t i, x;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < (size - 1); i++)
	{
		for (x = 0; x < (size - 1 - i); x++)
		{
			if (array[x] > array[x + 1])
			{
				swap(&array[x], &array[x + 1]);
				print_array(array, size);
			}
		}
	}
}

/**
 * swap - function to swap two integers.
 *
 * @a: the first integer to swap.
 * @b: the second integer to swap
*/
void swap(int *a, int *b)
{
int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
