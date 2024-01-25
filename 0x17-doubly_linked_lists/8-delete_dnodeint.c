#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes a node at a given position
 * @head: duoble pointer to the first element of the list
 * @index: the node that should be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int i = 0;
	dlistint_t *current;

	if (!head || !*head)
		return (-1);

	current = *head;

	if (index == 0)
	{
		*head = current->next;
		if (*head)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	while (i < index && current)
	{
		current = current->next;
		i++;
	}

	if (!current)
		return (-1);

	if (current->prev)
		current->prev->next = current->next;

	if (current->next)
		current->next->prev = current->prev;

	free(current);

	return (1);
}
