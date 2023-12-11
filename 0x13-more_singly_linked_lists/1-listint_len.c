#include "lists.h"

/**
 * listint_len - Counts the number of elements in a linked listint_t list
 * @h: pointer to first element of list
 *
 * Return: the count
*/
size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}
