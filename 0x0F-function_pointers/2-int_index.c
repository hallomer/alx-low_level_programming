#include "function_pointers.h"

/**
 * int_index - a function that searches for an integer
 * @array: array to search insaid
 * @size: number of elements in the array
 * @cmp: a pointer to the function to be used to compare values
 *
 * Return: the index of the first element or -1 if failed
*/

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array != NULL && cmp != NULL)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]))
			{
				return (i);
			}
		}
	}
	return (-1);
}
