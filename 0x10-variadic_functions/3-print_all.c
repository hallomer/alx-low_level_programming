#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - Prints anything
 * @format: A list of types of arguments
 *
 * Return: void
*/
void print_all(const char * const format, ...)
{
	va_list args;
	char *s;
	int i;
	char c;
	float f;

	va_start(args, format);

	while (*format)
	{
		switch (*format)
		{
			case 'c':
				c = va_arg(args, int);
				printf("%c", c);
				break;
			case 'i':
				i = va_arg(args, int);
				printf("%d", i);
				break;
			case 'f':
				f = va_arg(args, double);
				printf("%f", f);
				break;
			case 's':
				s = va_arg(args, char *);
				if (str == NULL)
					printf("nil");
				printf("%s", s);
				break;
			default:
				format++;
				continue;
		}
		if (*(format + 1))
			printf(", ");
		format++;
	}
	printf("\n");
	va_end(args);
}

