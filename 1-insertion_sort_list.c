#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *index, *aux;

	if (!list || !list[0] || !list[0]->next)
		return;

	index = (*list)->next;
	while (index != NULL)
	{
		aux = index;
		index = index->next;
		while (aux->prev && aux->n < aux->prev->n)
		{
			aux->prev->next = aux->next;
			aux->next = aux->prev;
			aux->prev = aux->next->prev;
			aux->next->prev = aux;
			if (aux->prev)
				aux->prev->next = aux;
			else
				*list = aux;
			if (aux->next->next)
				aux->next->next->prev = aux->next;
			print_list(*list);
		}
	}
}
