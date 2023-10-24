#include "sort.h"

/**
 * shell_sort - implementation of shell sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void shell_sort(int *array, size_t size)
{
	int i;
	size_t j, gap = 1;
	int tmp;

	if (!array)
		return;

	while (gap <= (size / 3))
		gap = (gap * 3) + 1;

	while (gap > 0)
	{
		for (j = gap - 1; j < size; j++)
		{
			for (i = j - gap; i >= 0; i = i - gap)
			{
				if (array[i + gap] >= array[i])
					break;
				tmp = array[i + gap];
				array[i + gap] = array[i];
				array[i] = tmp;
			}
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
