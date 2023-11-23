#include "main.h"
#include <stdlib.h>

/**
 * *malloc_checked - Allocates space in memory
 * @b: size of needed space in bytes
 *
 * Return: pointer or exit with 98 if it fails
*/
void *malloc_checked(unsigned int b)
{
	void *p = malloc(b);

	if (p == NULL)
	{
		exit(98);
	}

	return (p);
}
