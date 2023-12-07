#include "lists.h"

/**
 * print_list - Prints all elements of a list_t list
 * @h: a pointer to fisrt element of list
 *
 * Return: number of nodes
*/
size_t print_list(const list_t *h)
{
	size_t nodes_count = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);

		nodes_count++;
		h = h->next;
	}

	return (nodes_count);
}
