#include "lists.h"

/**
 * get_dnodeint_at_index - Gets the nth node of a dlistint_t linked list
 * @head: pointer to the first node of list
 * @index:  the index of the node, starting from 0
 *
 * Return: the node or if it does not exist, return NULL
*/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;
	dlistint_t *desired = head;

	if (!head)
		return (NULL);

	while ((i < index) && (desired->next))
	{
		desired = desired->next;
		i++;
	}

	return (desired);
}
