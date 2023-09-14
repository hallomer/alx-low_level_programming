#include "main.h"

/**
 * print_square - prints a square, followed by a new line
 * @size: parameter
 *
 * Return: void
*/

void print_square(int size)
{
	int h, a;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	h = 0;
	while (h < size)
	{
		a = 0;
		while (a < size)
		{
			_putchar('#');
			a++;
		}
		_putchar('\n');
		h++;
	}
}
