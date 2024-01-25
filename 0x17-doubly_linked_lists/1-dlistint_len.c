#include "lists.h"

/**
 * dlistint_len - Gets the length of a dlistint_t list
 * @h: pointer to the first node
 *
 * Return: the number of elements
*/
size_t dlistint_len(const dlistint_t *h)
{
	size_t len = 0;

	while (h)
	{
		h = h->next;
		len++;
	}
	return (len);
}
