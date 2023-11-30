#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_strings - Prints strings
 * @separator: the string to be printed between the strings
 * @n: number of parameters
 *
 * Return: nothing
*/
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	char *str;
	va_list args;

	if (n > 0)
	{
		va_start(args, n);

		if (separator == NULL)
			separator = "";

		for (i = 0; i < n; i++)
		{
			str = va_arg(args, char *);

			if (str == NULL)
				str = "(nil)";

			printf("%s", str);

			if (i < n - 1)
				printf("%s", separator);
		}

		va_end(args);
	}

	printf("\n");
}
