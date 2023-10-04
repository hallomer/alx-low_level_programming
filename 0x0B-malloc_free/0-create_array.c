#include "main.h"
#include <stdlib.h>

/**
 * *create_array - creates an array of chars,
 *	and initializes it with a specific char
 * @size: size of array
 * @c: the character to be initialized with
 *
 * Return: pointer to array or 0 if fails or size == 0
*/

char *create_array(unsigned int size, char c)
{
	char *arr;
	unsigned int i;

	if (size == 0)
	{
		return (NULL);
	}

	arr = malloc(size * sizeof(char));

	if (arr == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		arr[i] = c;
	}

	return (arr);
}
