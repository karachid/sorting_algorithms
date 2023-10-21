#include "sort.h"

/**
 * bubble_sort - Implements bubble sort algorithm
 * @array : Input array to be sorted
 * @size : size of the array to be sorted
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int sorted, tmp;

	if (!array)
		return;
	for (i = 0; i < size - 1; i++)
	{
		sorted = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				sorted = 1;
				print_array(array, size);
			}
		}
		if (!sorted)
			break;
	}
}
