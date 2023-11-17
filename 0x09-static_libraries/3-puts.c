#include "main.h"

/**
 * _puts - prints a string followed by a newline to stdout
 * @str: pointer
 *
 * Return: void
*/

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
