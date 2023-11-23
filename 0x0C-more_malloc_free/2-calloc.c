#include "main.h"
#include <stdlib.h>

/**
 * *_calloc - Allocates memory for an array
 * @nmemb: elements of the array
 * @size: size of one element
 *
 * Return: pointer or NULL if it fails
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int whole_size, i;
	char *p;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}

	whole_size = nmemb * size;

	p = malloc(whole_size);
	if (p == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < whole_size; i++)
	{
		p[i] = 0;
	}

	return (p);

}
