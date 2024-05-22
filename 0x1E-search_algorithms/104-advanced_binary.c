#include "search_algos.h"

/**
 * advanced_binary - Searches for a value in a sorted array
 *						using advanced binary search
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index where the value is located, or -1
*/
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	return (binary_search_recursive(array, 0, size - 1, value));
}

/**
 * binary_search_recursive - Helper function
 * @array: pointer to the first element of the array to search in
 * @start: start boundary of the subarray
 * @end: end boundary of the subarray
 * @value: value to search for
 *
 * Return: first index where the value is located, or -1
*/
int binary_search_recursive(int *array, size_t start, size_t end, int value)
{
	size_t mid, i;

	if (end >= start)
	{
		printf("Searching in array: ");
		for (i = start; i <= end; i++)
		{
			printf("%d", array[i]);
			if (i < end)
				printf(", ");
		}
		printf("\n");

		mid = start + (end - start) / 2;
		if (array[mid] == value && (mid == start || array[mid - 1] != value))
			return (mid);
		if (array[mid] >= value)
			return (binary_search_recursive(array, start, mid, value));
		return (binary_search_recursive(array, mid + 1, end, value));
	}
	return (-1);
}
