#include "sort.h"

/**
 * swap - Swaps two integers
 * @a : first input
 * @b : second input
 * Return: int (Always 1)
 */
int swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return (1);
}

/**
 * quick_sort - Implements quick  sort algorithm
 * @array : Array to be sorted
 * @size : size of the array
 */
void quick_sort(int *array, size_t size)
{
	int pivot, flag = 1, flag_loop;
	size_t i, j, len = size;

	if (!array || size == 0)
		return;
	while (flag)
	{
		flag_loop = 0;
		flag = 0;
		i = 0;
		j = 0;
		pivot = array[size - 1];
		while (i < size && pivot >= array[i])
		{
			i++;
			j++;
			if (array[i] == pivot && i == size - 1)
			{
				size = size - 1;
				flag_loop = 1;
				flag = 1;
			}
		}
		if (flag_loop == 1)
			continue;

		while (j < size && pivot < array[j])
			j++;
		if (i != j)
		{
			flag = swap(array + i, array + j);
			print_array(array, len);
		}
		if (flag == 0)
			break;
	}
}
