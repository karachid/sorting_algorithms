#include "sort.h"

/**
 * swap - swaps the array
 * @a : first input
 * @b : second input
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
 * quick_sort - Implements quick sort
 * @array : input array
 * @size : size of the array
 */

void quick_sort(int *a, size_t size)
{
	int pivot, flag = 1, flag_loop;
	size_t i, j, len = size, k = 0;

	while(flag)
	{
		flag_loop = 0;
		flag = 0;
		i = k;
		j = i;
		pivot = a[size - 1];
		while (i < size && pivot >= a[i])
		{
			i++;
			j++;
			if (a[i] == pivot && i == size - 1)
			{
				size = size - 1;
				flag_loop = 1;
				flag = 1;
				k = 0;
			}
		}
		if (flag_loop == 1)
			continue;
		k = i;
		while (j < size && pivot < a[j])
			j++;
		if (i != j)
		{
			flag = swap(a+i, a+j);
			print_array(a, len);
		}
		if (flag == 0)
			break;
	}
}
