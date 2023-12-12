#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list
 * @head: pointer to first element
 *
 * Return: number of nodes in the list
*/
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = NULL, *loop_check = NULL;
	size_t count = 0, loop_counter;

	current = head;
	while (current)
	{
		if (!head)
			exit(98);

		printf("[%p] %d\n", (void *)current, current->n);
		count++;

		current = current->next;
		loop_check = head;
		loop_counter = 0;

		while (loop_counter < count)
		{
			if (loop_check == current)
			{
				printf("-> [%p] %d\n", (void *)current, current->n);
				return (count);
			}
			loop_check = loop_check->next;
			loop_counter++;
		}
	}
	return (count);
}
