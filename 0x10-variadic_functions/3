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
	char *p_format = (char *) format;

	va_start(args, format);
	while (*p_format)
	{
		switch (*p_format)
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
				if (s == NULL)
					printf("nil");
				printf("%s", s);
				break;
			default:
				p_format++;
				continue;
		}
		if (*(p_format + 1))
			printf(", ");
		p_format++;
	}
	printf("\n");
	va_end(args);
}

