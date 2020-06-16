#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *index = *list, *aux;
	int swap = 1;

	if (!list || !index || !index->next)
		return;

	index = index->next;
	for (; index; index = index->next)
	{
		aux = index;
		while (aux->prev && aux)
		{
			if (aux->prev->n > aux->n)
			{
				swap_nodes(aux->prev, aux);
				if (!aux->prev)
					*list = aux;
				print_list(*list);
				if (swap == 1)
				{
					swap = 0;
					if (index->next)
						index = index->next;
				}
			}
			else
				aux = aux->prev;
		}
		swap = 1;
	}
}

/**
 * swap_nodes - Swap two nodes
 * @previous: first node
 * @current: second node
 */
void swap_nodes(listint_t *first, listint_t *second)
{
	if (first->prev)
		first->prev->next = second;
	if (second->next)
		second->next->prev = first;
	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
}
