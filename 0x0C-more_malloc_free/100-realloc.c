#include "main.h"
#include <stdlib.h>

/**
 * *_realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @old_size: size of ptr
 * @new_size: new size for new memory block
 *
 * Return: a pointer to allocated memory or NULL
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int min_size, i;
	char *dest, *src;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	if (new_size > old_size)
		min_size = old_size;
	else
		min_size = new_size;

	src = (char *)ptr;
	dest = (char *)new_ptr;
	for (i = 0; i < min_size; i++)
	{
		dest[i] = src[i];
	}

	free(ptr);
	return (new_ptr);
}
