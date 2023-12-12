#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list
 * @h: pointer to pointer to the first element of the list
 *
 * Return: the size of the list that was free’d
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *next;
	size_t list_size = 0;

	if (!h || !*h)
		return (0);

	current = *h;
	while (current)
	{
		next = current->next;
		free(current);
		list_size++;

		if (current <= next)
			break;

		current = next;
	}

	*h = NULL;
	return (list_size);
}
