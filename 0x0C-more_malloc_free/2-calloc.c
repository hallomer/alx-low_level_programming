#include "main.h"
#include <stdlib.h>

/**
 * *_calloc - allocates memory for an array, using malloc
 * @nmemb: number of elements
 * @size: bytes of each element
 *
 * Return: a pointer to allocated memory or NULL
*/

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int wholesize = nmemb * size, i;
	void *p;
	char *char_p;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	p = malloc(wholesize);
	if (p == NULL)
	{
		return (NULL);
	}


	char_p = (char *) p;

	for (i = 0; i < wholesize; i++)
	{
		char_p[i] = 0;
	}
	return (p);
}
