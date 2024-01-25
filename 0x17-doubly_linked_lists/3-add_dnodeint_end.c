#include "lists.h"

/**
 * add_dnodeint_end -  Adds a new node at the end of a dlistint_t list
 * @head: double pointer to first element
 * @n: node to add
 *
 * Return: the address of the new element, or NULL if it failed
*/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *last_node = NULL;
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (!*head)
		*head = new_node;
	else
	{
		last_node = *head;
		while (last_node->next)
			last_node = last_node->next;

		last_node->next = new_node;
		new_node->prev = last_node;
	}

	return (new_node);
}
