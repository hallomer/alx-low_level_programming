#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position
 * @head: pointer to pointer to first element of list
 * @idx: index of the list where the new node should be added
 * @n: node to insert
 *
 * Return: address of the new node, or NULL if it failed
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *temp;
	unsigned int i;

	if (!head)
		return (NULL);

	if (idx > 0)
	{
		temp = *head;
		for (i = 0; i < idx - 1; i++)
		{
			temp = temp->next;
			if (!temp)
				return (NULL);
		}
	}

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	new_node->next = temp->next;
	temp->next = new_node;

	return (new_node);
}
