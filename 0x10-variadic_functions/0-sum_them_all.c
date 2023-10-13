#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all -  Adds all its parameters
 * @n: number of integers
 *
 * Return: the sum or 0
*/
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i, j, sum = 0;
	va_list args;

	if (n == 0)
	{
		return (0);
	}

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		j = va_arg(args, int);
		sum += j;
	}
	return (sum);
	va_end(args);
}
