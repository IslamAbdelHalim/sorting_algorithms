#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integers in ascending order.
 * @array: the input array to be sorted.
 * @size: size of the input array.
 */

void bubble_sort(int *array, size_t size)
{
size_t i, x;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (x = 0; x < (size - i - 1); x++)
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
 * @a: first number to swap.
 * @b: second number to swap.
 */

void swap(int *a, int *b)
{
int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
