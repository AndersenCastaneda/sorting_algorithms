#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swap two nodes
 * @first: first node
 * @second: second node
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

/**
 * insertion_sort_list - Sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *index = *list, *aux;

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
			}
			else
				aux = aux->prev;
		}
	}
}
