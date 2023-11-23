#include "main.h"
#include <stdlib.h>

/**
 * *_realloc - A function thats reallocates a memory block
 * @ptr: a pointer to the memory previously allocated
 * @old_size: size of the allocated space for ptr
 * @new_size: new size of the new memory block
 *
 * Return: a pointer or NULL if it fails
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	char *src, *dest;
	unsigned int i, copy_size = old_size < new_size ? old_size : new_size;;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size <= old_size)
		return (ptr);

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	src = (char *)ptr;
	dest = (char *)new_ptr;
	for (i = 0; i < copy_size; i++)
		dest[i] = src[i];

	free(ptr);

	return (new_ptr);
}
