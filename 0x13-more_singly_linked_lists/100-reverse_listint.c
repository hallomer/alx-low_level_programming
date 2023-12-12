#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list
 * @head: pointer to pointer to the first element of the list
 *
 * Return: pointer to the first node of the reversed list
*/
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *current = *head;


	while (current)
	{
		*head = current->next;
		current->next = prev;
		prev = current;
		current = *head;
	}
	*head = prev;
	return (*head);
}
