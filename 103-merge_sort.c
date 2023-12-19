#include "sort.h"
#include <stdlib.h>

/**
 * merge_sort - function that making sorting merge algorithm
 *
 * @array: The array of unsorted element
 *
 * @size: size of array
*/
void merge_sort(int *array, size_t size)
{
	int down, top, *temp_array;

	if (!array || size < 2)
		return;
	/*Define the top and down of array*/
	down = 0;
	top = size - 1;
	/*Making a temporary array that take a sorted element*/
	temp_array = malloc(sizeof(int) * size);
	if (temp_array == NULL)
		return;

	/*Recursion function devided array until become each element as signle array*/
	merge_subarray(array, temp_array, down, top);

	free(temp_array);
}

/**
 * merge_subarray - function devided array and merge it to sort
 *
 * @array: The main array
 *
 * @temp_array: array that store the array element sorted
 *
 * @down: The first element of subarray
 *
 * @top: The last element of subarray
*/
void merge_subarray(int *array, int *temp_array, int down, int top)
{
	int mid;

	if (down < top)
	{
		mid = down + (top - down) / 2;

		/*left subarray*/
		merge_subarray(array, temp_array, down, mid);
		/*right subarray*/
		merge_subarray(array, temp_array, mid + 1, top);

		/*Making merge with each to list*/
		merge(array, temp_array, down, mid, top);
	}
}

/**
 * merge - function that merge the two subArray
 *
 * @array: The main array
 *
 * @temp_array: the array which store the sorted element
 *
 * @down: The first element of subarray
 *
 * @mid: The mid element which split array
 *
 * @top: The last element of subarray
*/

void merge(int *array, int *temp_array, int down, int mid, int top)
{
	int i, j, k;
	/**
	 * i => for the first sub array
	 * j => for the second sub array
	 * k => for the temp_array
	 */
	i = down, j = mid, k = down;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + down, mid - down + 1);
	printf("[right]: ");
	print_array(array + mid + 1, top - mid);

	while (i <= mid && j <= top)
	{
		if (i == mid)
			temp_array[k++] = array[j++];
		else if (j == top + 1)
			temp_array[k++] = array[i++];
		else if (array[i] < array[j])
			temp_array[k++] = array[i++];
		else
			temp_array[k++] = array[j++];
	}
	/*for remaining element*/
	for (; i <= mid; i++)
		temp_array[k++] = array[i];
	for (; j <= top; j++)
		temp_array[k++] = array[j];

	/*tranfare the sorted element into main array*/
	for (k = down; k <= top; k++)
		array[k] = temp_array[k];
	printf("[Done]: ");
	print_array(array + down, top - down + 1);
}
