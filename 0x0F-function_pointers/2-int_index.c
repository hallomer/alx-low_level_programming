#include "function_pointers.h"

/**
 * int_index - Searches for an integer
 * @array: array of integers to be searched
 * @size: size of array
 * @cmp: a pointer to a function
 *
 * Return: index to first match, or -1 if it fails
*/
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (size <= 0)
	{
		return (-1);
	}

	if (array != NULL && cmp != NULL)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]) != 0)
				return (i);
		}
	}

	return (-1);
}
