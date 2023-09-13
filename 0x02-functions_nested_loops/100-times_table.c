#include "main.h"
/**
 * print_times_table - prints the n times table
 * @n: parameter
 *
 * Return: void
*/
void print_times_table(int n)
{
	int z = 0, rw, cl;

	if (n > 15 || n < 0)
		return;
	while (z <= n)
	{
		for (rw = 0; rw <= n; rw++)
		{
			cl = z * rw;
			if (cl > 99)
			{
				_putchar(cl / 100 + '0');
				_putchar((cl / 10 % 10) + '0');
				_putchar(cl % 10 + '0');
			}
			else if (cl > 9)
			{
				_putchar(' ');
				_putchar(cl / 10 + '0');
				_putchar(cl % 10 + '0');
			}
			else if (rw != 0)
			{
				_putchar(' ');
				_putchar(' ');
				_putchar(cl + '0');
			}
			else
				_putchar(cl + '0');

			if (rw != n)
			{
				_putchar(',');
				_putchar(' ');
			}
		}
		_putchar('\n');
		z++;
	}
}
