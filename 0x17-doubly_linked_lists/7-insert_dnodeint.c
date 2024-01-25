#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 * @h: duoble pointer to the first element of the list
 * @idx: where the new node should be added
 * @n: node to add
 *
 * Return: the address of the new node, or NULL if it failed
*/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i = 0;
	dlistint_t *current = *h;
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	if (!new_node || !*h)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (idx == 0)
	{
		new_node->next = *h;
		if (*h)
			(*h)->prev = new_node;
		*h = new_node;
		return (new_node);
	}

	while ((i < idx - 1) && current && (current->next))
	{
		new_node->prev = current;
		current = current->next;
		i++;
	}

	if (i != idx - 1)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = current->next;
	if (current->next != NULL)
		current->next->prev = new_node;
	new_node->prev = current;
	current->next = new_node;

	return (new_node);
}
