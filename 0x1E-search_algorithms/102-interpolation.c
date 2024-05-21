#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array
 *							using Interpolation search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index where the value is located, or -1
*/
int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0;
	size_t high = size - 1;
	size_t pos;

	if (array == NULL)
		return (-1);

	while ((array[high] != array[low]))
	{
		pos = low + (((double)(high - low)
				/ (array[high] - array[low]))
			       * (value - array[low]));

		if (pos > size)
		{
			printf("Value checked array[%lu] is out of range\n"
			       , pos);
			return (-1);
		}
		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);
		if (value > array[pos])
			low = pos + 1;
		else if (value < array[pos])
			high = pos - 1;
		else
			return (pos);
	}

	if (value == array[low])
		return (low);
	else
		return (-1);
}
