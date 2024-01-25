#include "lists.h"

/**
 * sum_dlistint - Gets the sum of all the data of a dlistint_t linked list
 * @head: pointer to the first element of the list
 *
 * Return: the sum, if the list is empty, return 0
*/
int sum_dlistint(dlistint_t *head)
{
	unsigned int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
