#include "lists.h"

/**
 * add_node_end - Adds a new node at the end of a list_t list
 * @head: a pointer to a  pointer to the first element of list
 * @str: string to be stored in the new element
 *
 * Return: the address of the new element or NULL if it fails
*/
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *temp;
	unsigned int len = 0, i = 0;

	while (str[len])
		len++;
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = malloc((len + 1) * sizeof(char));
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	for (i = 0; i <= len; i++)
		new_node->str[i] = str[i];

	new_node->len = len;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
	return (new_node);
}
