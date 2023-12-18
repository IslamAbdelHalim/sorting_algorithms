#ifndef __SORT_H__
#define __SORT_H__

/***********Header_files*****/
#include <stdio.h>
#include <stdlib.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/********Functions******/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap(int *xp, int *yp);

void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);

int findMax(int *array, size_t size);
void countingSort(int *array, ssize_t size, int exp);
void radix_sort(int *array, size_t size);
#endif /* __SORT_H__ */
