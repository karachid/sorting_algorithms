#include "sort.h"

/**
 * swap - swaps two values
 * @a : first input
 * @b : second input
 * Return: void (NOTHING)
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * biggest_gap - calculates the biggest gap according to size
 * @size : size according to which gap will be calculated
 * Return: int (biggest gab)
 */
int biggest_gap(size_t size)
{
	int gap = 1, res = 1;

	while (gap < (int)size)
	{
		res = gap;
		gap = (gap * 3 + 1);
	}
	return (res);
}

/**
 * shell_sort - implements shell short algorithm (Knuth sequence)
 * @array : array to be implemented
 * @size : size of the array to be sorted
 */
void shell_sort(int *array, size_t size)
{
	int i, j, gap;

	if (!array || size == 0)
		return;

	gap = biggest_gap(size);

	while (gap)
	{
		for (i = gap; i < (int)size; i++)
		{
			j = i;
			while (j - gap >= 0)
			{
				if (array[j] < array[j - gap])
					swap(array + j, array + j - gap);

				j -= gap;
			}
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
