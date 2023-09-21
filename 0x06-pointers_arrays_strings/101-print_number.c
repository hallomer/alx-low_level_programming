#include "main.h"

/**
 * print_number - prints an integer
 * @n: input number
 *
 * Return: void
*/

void print_number(int n)
{
	unsigned int i;

	if (n < 0)
	{
		_putchar('-');
		i = n * -1;
	}
	else
	{
		i = n;
	}
	if (i / 10)
	{
		print_number(i / 10);
	}
	_putchar ((i % 10) + '0');
}
