#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list & set head to NULL
 * @head: pointer to pointer to first element of list
 *
 * Return: nothing
*/
void free_listint2(listint_t **head)
{
	listint_t *p;

	if (!head)
		return;

	p = *head;
	while (*head)
	{
		p = p->next;
		free(*head);
		*head = p;
	}
}
