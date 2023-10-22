#include "sort.h"

/**
 * insertion_sort_list - implement insert sort algorithm
 * @list: head of the nodes
 * Return: nothing
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr1, *curr2, *tmp;

	if (list == NULL || *list == NULL)
		return;
	curr1 = (*list)->next;
	while (curr1)
	{
		tmp = curr1;
		curr2 = tmp->prev;
		curr1 = curr1->next;
		while (curr2 && curr2->n > tmp->n)
		{
			curr2->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = curr2;
			tmp->next = curr2;
			tmp->prev = curr2->prev;
			if (curr2->prev)
				curr2->prev->next = tmp;
			if (curr2->prev == NULL)
				*list = tmp;
			curr2->prev = tmp;
			curr2 = tmp->prev;
			print_list(*list);
		}
	}
}
