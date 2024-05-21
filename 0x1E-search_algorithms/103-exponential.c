#include "search_algos.h"

/**
 * binary_search_recursive - Recursively searches for a value in a sorted array
 *								using Binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @start: start index of the subarray to search
 * @end: end index of the subarray to search
 * @value: value to search for
 *
 * Return: first index where the value is located, or -1
*/
int binary_search_recursive(int *array, size_t start, size_t end, int value)
{
	size_t mid, i;

	if (start > end)
		return (-1);

	mid = start + (end - start) / 2;

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i < end)
			printf(", ");
	}
	printf("\n");

	if (array[mid] == value)
		return (mid);
	if (array[mid] < value)
		return (binary_search_recursive(array, mid + 1, end, value));
	else
		return (binary_search_recursive(array, start, mid - 1, value));
}

/**
 * exponential_search - Searches for a value in a sorted array
 *						using Exponential search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index where the value is located, or -1
*/
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1, start, end;

	if (array == NULL)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	start = bound / 2;
	end = (bound < size) ? bound : size - 1;

	printf("Value found between indexes [%lu] and [%lu]\n", start, end);

	return (binary_search_recursive(array, start, end, value));
}
