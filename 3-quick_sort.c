#include "sort.h"

/**
 * swap - Swap two values on an array
 * @array: Array to swap
 * @a: First index to swap
 * @b: Second index to swap
 */
void swap(int *array, int a, int b)
{
	int temp = array[a];

	array[a] = array[b];
	array[b] = temp;
}

/**
 * quick_recursion - Sorts using recursion
 * @array: Array to sort
 * @start: Start index
 * @end: End index
 * @size: Size of array
 */
void quick_recursion(int *array, int start, int end, size_t size)
{
	long int partitionIndex = start - 1, i;

	if (start < end)
	{
		for (i = start; i < end; i++)
		{
			if (array[i] <= array[end])
			{
				partitionIndex++;
				if (partitionIndex != i)
				{
					swap(array, partitionIndex, i);
					print_array(array, size);
				}
			}
		}
		if (partitionIndex + 1 != end)
		{
			swap(array, partitionIndex + 1, end);
			print_array(array, size);
		}
		quick_recursion(array, start, partitionIndex, size);
		quick_recursion(array, partitionIndex + 2, end, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: Array to sort
 * @size: Size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_recursion(array, 0, size - 1, size);
}
