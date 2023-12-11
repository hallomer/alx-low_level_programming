#include "lists.h"

/**
 * sum_listint - Returns the sum of all the data of a listint_t linked list
 * @head: pointer to first element of list
 *
 * Return: the sum, or 0 if it fails
*/
int sum_listint(listint_t *head)
{
	listint_t *p = head;
	int sum = 0;

	if (head != NULL)
	{
		while (p)
		{
			sum += p->n;
			p = p->next;
		}

		return (sum);
	}

	return (0);
}
