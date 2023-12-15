#include "sort.h"
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

/**
 * selection_sort - fun to sort
 * @array: array to sort
 * @size: size of array
*/

void selection_sort(int *array, size_t size) 
{
    size_t i, j, min_index;

    for (i = 0; i < size - 1; i++) 
    {
        min_index = i;
        for (j = i + 1; j < size; j++)
         {
            if (array[j] < array[min_index]) 
            {
                min_index = j;
            }
        }
        if (min_index != i) 
        {
            swap(&array[i], &array[min_index]);
            print_array(array, size);
        }
    }
}
