#include "main.h"
#include <stdlib.h>

/**
 * *array_range - creates an array of integers
 * @min: min elements
 * @max: max elements
 *
 * Return: a pointer to allocated memory or null
*/

int *array_range(int min, int max)
{
	int range, i;
	int *arr;

	if (min > max)
	{
		return (NULL);
	}

	range = max - min + 1;

	arr = malloc(range * sizeof(int));
	if (arr == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < range; i++)
	{
		arr[i] = min + i;
	}
	return (arr);
}
