#include "function_pointers.h"

/**
 * printer - a function that prints characters
 * @c: characters to be printed
 *
 * Return: void
*/

void printer(char *c)
{
	while (*c != '\0')
	{
		_putchar(*c);
		c++;
	}
}

/**
 * print_name - a function that prints a name
 * @name: the name to be printed
 * @f: pointer to a function that takes char as parameter and return nothing
 *
 * Return: void
*/
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
