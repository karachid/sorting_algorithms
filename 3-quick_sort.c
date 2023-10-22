#include "sort.h"

/**
 * swap - swaps the array
 * @arr : array
 * @size : size
 * @a : first input
 * @b : second input
 */
void swap(int *arr, size_t size, int *a, int *b)
{

	int temp = *a;
	*a = *b;
	*b = temp;

	print_array(arr, size);

}

/**
 * lomuto_partition - partitions the array
 * @arr : array
 * @size : size
 * @low : low
 * @high : high
 * Return: int
 */
int lomuto_partition(int *arr, size_t size, int low, int high)
{
	int pivot = arr[high];
	int i, j;

	for (i = j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			swap(arr, size, &arr[j], &arr[i++]);
		}
	}
	swap(arr, size, &arr[i], &arr[high]);
	return (i);
}

/**
 * partition_sort - Recursive calls
 * @arr : array
 * @size : size
 * @low : low
 * @high : high
 */
void partition_sort(int *arr, size_t size, int low, int high)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(arr, size,  low, high);

		partition_sort(arr, size,  low, pivot_index - 1);
		partition_sort(arr, size, pivot_index + 1, high);
	}
}

/**
 * quick_sort - Implements quick sort
 * @array : input array
 * @size : size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array)
		return;

	partition_sort(array, size, 0, size - 1);
}
