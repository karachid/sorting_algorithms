#include "sort.h"

/**
 * get_max - gets the max value of the input array
 * @arr : input array
 * @s : size of the input array
 * Return: int (MAX VALUE)
 */
int get_max(int *arr, size_t s)
{
	int i, max = arr[0];

	for (i = 1; i < (int)s; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return (max);
}

/**
 * counting_sort - implements the counting sort algorithm
 * @array : input array to be sorted
 * @size : size of the input array
 * Return: void (NOTHING)
 */
void counting_sort(int *array, size_t size)
{
	int i, max, *countArray = NULL, *outputArray = NULL;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	countArray = malloc(sizeof(int) * (max + 1));
	outputArray = malloc(sizeof(int) * size);

	for (i = 0; i < (int)size; i++)
	{
		countArray[array[i]]++;
	}

	for (i = 1; i < max + 1; i++)
	{
		countArray[i] += countArray[i - 1];
	}

	print_array(countArray, max + 1);

	for (i = size - 1; i >= 0; i--)
	{
		outputArray[countArray[array[i]] - 1] = array[i];
		countArray[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
	{
		array[i] = outputArray[i];
	}

	free(countArray);
	free(outputArray);
}
