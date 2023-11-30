#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - A function that prints anything
 * @format: list of types of arguments passed to the function
 *
 * Return: nothing
*/
void print_all(const char * const format, ...)
{
	char character, *string;
	int i = 0, integer;
	float float_num;
	va_list args;

	va_start(args, format);
	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				character = va_arg(args, int);
				printf("%c", character);
				break;
			case 'i':
				integer = va_arg(args, int);
				printf("%d", integer);
				break;
			case 'f':
				float_num = va_arg(args, double);
				printf("%f", float_num);
				break;
			case 's':
				string = va_arg(args, char *);
				if (string == NULL)
					printf("(nil)");
				printf("%s", string);
				break;
			default:
				break;
		}
		if (format[i + 1] != '\0' && (format[i] == 'c' || format[i] == 'i' ||
						format[i] == 'f' || format[i] == 's'))
		{
			printf(", ");
		}
		i++;
	}
	printf("\n");
	va_end(args);
}

