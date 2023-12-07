#include "lists.h"

/**
 * list_len - Returns the number of elements in a linked list_t list
 * @h: a pointer to fisrt element of list
 *
 * Return: nodes count
*/
size_t list_len(const list_t *h)
{
	size_t nodes_count = 0;

	while (h != NULL)
	{
		nodes_count++;
		h = h->next;
	}

	return (nodes_count);
}
