#include "function_pointers.h"

/**
 * array_iterator - executes a function given as a parameter
 * @array: array of functions
 * @size: size of array
 * @action: a pointer to the function
 *
 * Return: nothing
*/
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
