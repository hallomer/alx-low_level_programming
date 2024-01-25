#include "lists.h"

/**
 * free_dlistint - Frees a dlistint_t list
 * @head: pointer to fist element of the list to free
 *
 * Return: nothing
*/
void free_dlistint(dlistint_t *head)
{
	dlistint_t *to_free;

	while (head)
	{
		to_free = head;
		head = head->next;
		free(to_free);
	}
}
