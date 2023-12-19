#include "sort.h"

/**
 * findMax - fun sort
 * @array: to sort it
 * @size: of it
*/
int findMax(int *array, size_t size) 
{
size_t i;
int max;

    max = array[0];
    for (i = 1; i < size; i++) 
    {
        if (array[i] > max) 
        {
            max = array[i];
        }
    }
    return (max);
}

/**
 * countingSort - fun sort
 * @array: to sort
 * @size: to sort
 * @exp: to sort
 * 
*/

void countingSort(int *array, ssize_t size, int exp)
{
    const ssize_t base = 10;
    int *output = malloc(size * sizeof(int));
    int *count = calloc(base, sizeof(int));
    ssize_t i;  

    if (output == NULL || count == NULL)
    {
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < size; i++)
    {
        count[(array[i] / exp) % base]++;
    }

    for (i = 1; i < base; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = size - 1; i >= 0; i--)  
    {
        output[count[(array[i] / exp) % base] - 1] = array[i];
        count[(array[i] / exp) % base]--;
    }

    for (i = 0; i < size; i++)
    {
        array[i] = output[i];
    }

    free(output);
    free(count);
}


/**
 * radix_sort - fun sort
 * @array: to sort
 * @size: to sort
 * 
 * 
*/
void radix_sort(int *array, size_t size) 
{
size_t i;
int exp, max;

    if (size <= 1)
    {
        return;
    }

    max = findMax(array, size);

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(array, size, exp);
        for (i = 0; i < size; i++) 
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
}
