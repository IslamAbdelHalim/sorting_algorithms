#include "sort.h"

/**
 * insertion_sort_list - function used to
 *	make insertion sort to linked list
 *
 * @list: doubly linked list
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous, *second;

	/*check if no list of size less than 2*/

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next; /*start from current Node*/

	while (current)
	{
		previous = current->prev;
		second = current->next;

		while (previous && previous->n > current->n)
		{
			current->next = previous;
			current->prev = previous->prev;
			previous->prev = current;
			previous->next = second;

			if (current->prev != NULL)
				current->prev->next = current;
			if (second != NULL)
				second->prev = previous;
			if (current->prev == NULL)
				*list = current;
			print_list(*list);
			previous = current->prev;
			second = current->next;
		}
		current = second;
	}
}
