#include "lists.h"

/**
 * free_list - Frees a list_t list
 * @head: a pointer to the first element of list
 *
 * Return: nothing
*/
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
	}
}
