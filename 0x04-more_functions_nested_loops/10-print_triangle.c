#include "main.h"
/**
 * print_triangle - prints a triangle, followed by a new line
 * @size: parameter
 *
 * Return: 0
*/
void print_triangle(int size)
{
	int i, j, r;

	if (size < 1)
	{
		_putchar('\n');
	}
	for (i = 1; i <= size; i++)
	{
		for (j = 1; j <= size - i; j++)
		{
			_putchar(' ');
		}
		for (r = 1; r <= i; r++)
		{
			_putchar('#');
	
		}
		_putchar('\n');
	}
}
