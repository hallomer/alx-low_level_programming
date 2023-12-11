#include "lists.h"

/**
 * get_nodeint_at_index -  Gets the nth node of a listint_t linked list
 * @head: pointer to first element of list
 * @index: index of node to return
 *
 * Return: address of nth node, or NULL if it fails
*/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *p;
	unsigned int i;

	for (i = 0; i < index; i++)
	{
		p = head->next;
	}

	return (p);
}
