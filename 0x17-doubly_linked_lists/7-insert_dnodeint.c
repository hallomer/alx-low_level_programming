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
	dlistint_t *new_node, *current = *h;

	if (!current && idx != 0)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = current;
		new_node->prev = NULL;
		if (current)
			current->prev = new_node;
		*h = new_node;
	}
	else
	{
		while (idx--)
		{
			if (current->next == NULL && idx == 0)
			{
				return (add_dnodeint_end(&current, n));
			}
			if (current->next == NULL && idx != 0)
				return (NULL);
			current = current->next;
		}
		new_node->next = current;
		new_node->prev = current->prev;
		current->prev->next = new_node;
		current->prev = new_node;
	}

	return (new_node);
}
