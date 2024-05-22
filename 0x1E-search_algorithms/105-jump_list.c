#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted singly linked list
 *				using jump search
 * @list: pointer to the head of the list
 * @size: number of nodes in the list
 * @value: value to search for
 *
 * Return: pointer to the first node where the value is located, or NULL
*/
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, prev;
	listint_t *node, *prev_node;

	if (list == NULL)
		return (NULL);

	step = sqrt(size);
	prev = 0;
	node = list;

	while (node->next && node->index < size - 1 && node->n < value)
	{
		prev_node = node;
		prev += step;
		while (node->next && node->index < prev)
			node = node->next;
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		   prev_node->index, node->index);

	while (prev_node && prev_node->index <= node->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				prev_node->index, prev_node->n);
		if (prev_node->n == value)
			return (prev_node);
		prev_node = prev_node->next;
	}

	return (NULL);
}
