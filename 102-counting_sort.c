#include "sort.h"
/**
 * max - function that get the maximum number of an array
 * @array: the input to get the max from it
 * @size: the length of the array
 * Return: get the(max) number  
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
 * counting_sort - function to perform the counting sort algorithm
 * @array: the array to be sorted
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

    count = malloc(k * sizeof(size_t));
    if (count == NULL)
        return;

    sorted_arr = malloc(size * sizeof(size_t));
    if (sorted_arr == NULL)
    {
        free(count);
        return;
    }

    for (y = 0; y < size; y++)
        count[array[y]]++;

    for (y = 0; y < k; y++)
        count[y] += count[y - 1];

    print_array(count, k);

    for (y = (size - 1); y > 0 ; --y)
        sorted_arr[--count[array[y]]] = array[y];

    for (y = 0; y < size; y++)
        array[y] = sorted_arr[y];

    free(sorted_arr);
    free(count);


}
