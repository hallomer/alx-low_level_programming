#include "main.h"

/**
 * times_table - prints the 9 times table
 *
 * Return: 0
*/

void times_table(void)
{
	int u, w, x, y, z;

	for (u = 0 ; u <= 9 ; u++)
	{
		for (w = 0 ; w <= 9 ; w++)
		{
			x = u * w;
			if (x > 9)
			{
				y = x % 10;
				z = (x - y) / 10;
				_putchar(44);
				_putchar(32);
				_putchar(z + '0');
				_putchar(y + '0');
			}
			else
			{
				if (w != 0)
				{
				_putchar(44);
				_putchar(32);
				_putchar(32);
				}
			_putchar(x + '0');
			}
		}
	_putchar('\n');
	}
}
