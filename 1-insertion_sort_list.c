#include "sort.h"

/**
 * insertion_sort_list - Implements insertion sort
 * @list : head of the list
 * Return: void (NOTHING)
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *c, *k, *tmp;

	if (list == NULL || *list == NULL)
		return;

	c = *list;

	while (c != NULL)
	{
		k = c;
		while (k->prev != NULL && k->n < k->prev->n)
		{
			/* Swap */
			tmp = k->prev;
			tmp->next = k->next;
			if (k->next)
				k->next->prev = tmp;
			if (!tmp->prev)
			{
				k->next = tmp;
				tmp->prev = k;
				k->prev = NULL;
				*list = k;
			}
			else
			{
				tmp->prev->next = k;
				k->prev = tmp->prev;
				tmp->prev = k;
				k->next = tmp;
			}
			print_list(*list);
		}
		/*Move c to the next item*/
		c = c->next;
	}
}
