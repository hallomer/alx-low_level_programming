#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list
 * @head: pointer to pointer to first element of list
 *
 * Return: the head node’s data (n)
*/
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n;

	if (head == NULL || *head == NULL)
		return (0);

	temp = *head;
	n = temp->n;
	*head = temp->next;
	free(temp);

	return (n);
}
