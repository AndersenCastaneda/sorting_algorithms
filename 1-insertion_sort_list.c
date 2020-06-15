#include "sort.h"
#include <stdio.h>

long unsigned int len(listint_t *head)
{
	long unsigned int count;

	for (count = 0; head; head = head->next)
		count++;

	return (count);
}

/**
 * insertion_sort_list - Sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *index = *list, *prev, *node;

	if (!list || !*list || len(*list) < 2)
		return;

	index = index->next;
	for (; index; index = index->next)
	{
		node = index;
		prev = node->prev;
		while (prev && node->n < prev->n)
		{
			prev->next = node->next;
			if (node->next)
				node->next->prev = prev;
			node->next = prev;
			node->prev = prev->prev;
			prev->prev = node;
			print_list(*list);
			printf("len: %lu\n", len(*list));
			prev = prev->prev;
		}
	}
}
