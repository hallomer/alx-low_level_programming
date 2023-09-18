#include "main.h"

/**
 * print_rev - prints a string in revers
 * @s: pointer
 *
 * Return: void
*/

void print_rev(char *s)
{
	int length, i;
	char *ptr;

	if (s == 0)
	{
		return;
	}

	length = 0;
	ptr = s;
	i = length - 1;

	while (*ptr != '\0')
	{
		length++;
		ptr++;
	}

	for (i = length - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}
