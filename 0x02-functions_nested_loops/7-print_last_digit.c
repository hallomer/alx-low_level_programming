#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @y: parameter to be checked
 *
 * Return: i
*/

int print_last_digit(int y)
{
	int i;

	i = y % 10;
	if (y < 0)
	{
		i = -i;
	}
	_putchar(i + '0');
	return (i);
}
