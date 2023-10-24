#include "sort.h"

/**
 * swap - function swap two nodes
 * @list: head of the list
 * @curr: first node to swap
 * @tmp: second node to swap
 * Return: Always 1
 */

int swap(listint_t **list, listint_t *curr, listint_t *tmp)
{
	curr->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = curr;
	tmp->next = curr;
	tmp->prev = curr->prev;
	if (curr->prev)
		curr->prev->next = tmp;
	if (curr->prev == NULL)
		*list = tmp;
	curr->prev = tmp;

	return (1);
}

/**
 * cocktail_sort_list - implementation of cocktail sort algorithm
 * @list: head of the list
 */

void cocktail_sort_list(listint_t **list)
{
	int flag = 1;
	listint_t *curr, *tmp;

	curr = *list;
	while (flag)
	{
		flag = 0;
		while (curr->next)
		{
			tmp = curr->next;
			if (curr->n > tmp->n)
			{
				flag = swap(list, curr, tmp);
				print_list(*list);
			}
			else
				curr = curr->next;
		}
		if (flag == 0)
			break;
		flag = 0;
		curr = tmp;
		while (curr->prev)
		{
			tmp = curr->prev;
			if (tmp->n > curr->n)
			{
				flag = swap(list, tmp, curr);
				print_list(*list);
			}
			else
				curr = curr->prev;
		}
	}
}
