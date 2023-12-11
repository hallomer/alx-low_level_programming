#include "lists.h"

/**
 * free_listint - Frees a listint_t list
 * @head: pointer to first element of list
 *
 * Return: nothing
*/
void free_listint(listint_t *head)
{
	listint_t *p;

	while (head)
	{
		p = head->next;
		free(head);
		head = p;
	}

}
