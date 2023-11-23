#include "main.h"
#include <stdlib.h>

/**
 * *array_range - Creates an array of integers
 * @min: minimum value of array
 * @max: maximum value of array
 *
 * Return: a pointer or NULL if it fails
*/
int *array_range(int min, int max)
{
	int array_size, *array, i;

	if (min > max)
		return (NULL);

	array_size = max - min + 1;

	array = malloc(sizeof(int) * array_size);
	if (array == NULL)
		return (NULL);

	for (i = 0; i < array_size; i++)
	{
		array[i] = min++;
	}

	return (array);

}
