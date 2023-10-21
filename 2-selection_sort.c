#include "sort.h"

/**
 * selection_sort -implement selection sort algorithm
 * @array: input array to the sorted
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, k;
	int min;

	if (!array)
		return;
	for (i = 0; i < size; i++)
	{
		min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				k = j;
			}
		}
		if (k != i)
		{
			array[k] = array[i];
			array[i] = min;
			print_array(array, size);
		}
	}
}
