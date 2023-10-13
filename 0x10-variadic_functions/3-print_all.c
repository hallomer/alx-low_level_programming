#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>


/**
 * print_char - Prints a character
 * @args: va_list argument
*/
void print_char(va_list args)
{
	char c = va_arg(args, int);

	printf("%c", c);
}

/**
 * print_int - Prints an integer
 * @args: va_list argument
*/
void print_int(va_list args)
{
	int d = va_arg(args, int);

	printf("%d", d);
}

/**
 * print_float - Prints a float
 * @args: va_list argument
*/
void print_float(va_list args)
{
	double f = va_arg(args, double);

	printf("%f", f);
}

/**
 * print_string - Prints a string
 * @args: va_list argument
 *         if the string is NULL, prints "(nil)"
*/
void print_string(va_list args)
{
	char *s = va_arg(args, char *);

	if (s == NULL)
	{
		printf("(nil)");
	}
	printf("%s", s);
}

/**
 * print_all - Prints anything
 * @format: A list of types of arguments
 *
 * Return: void
*/
void print_all(const char * const format, ...)
{
	int i = 0, args_n;
	va_list args;
	void (*print_func)(va_list);

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == 'c' || format[i] == 'i' ||
				format[i] == 'f' || format[i] == 's')
			args_n++;
		i++;
	}
	i = 0;
	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				print_func = print_char;
				break;
			case 'i':
				print_func = print_int;
				break;
			case 'f':
				print_func = print_float;
				break;
			case 's':
				print_func = print_string;
				break;
			default:
				i++;
				continue;
		}
		print_func(args);
		if (i < args_n)
			printf(", ");
		i++;
	}
	printf("\n");
	va_end(args);
}

