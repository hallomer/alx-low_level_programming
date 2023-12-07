#include "lists.h"

/**
 * add_node - Adds a new node at the beginning of a list_t list
 * @head: a pointer to a pointer to the first element of the list
 * @str: string to be stored in the new element
 *
 * Return: the address of the new element or NULL if it fails
*/
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	unsigned int length = 0;

	while (str[length] != '\0')
		length++;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->len = length;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
