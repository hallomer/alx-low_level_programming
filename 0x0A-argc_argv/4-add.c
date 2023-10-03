#include "main.h"

/**
 * is_digit - checks if a character is a digit
 * @c: character to be checked
 *
 * Return: 1 if digit, 0 otherwise
*/
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * is_positive_number - checks if a string is a positive number
 * @s: string
 *
 * Return: 1 if positive, 0 otherwise
*/
int is_positive_number(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (!is_digit(s[i]))
		{
			return (0);
		}
		i++;
	}

	return (1);
}

/**
 * print_number - prints a number
 * @n: number
 *
 * Return: void
*/
void print_number(int n)
{
	if (n / 10 != 0)
	{
		print_number(n / 10);
	}
	_putchar(n % 10 + '0');
}

/**
 * _atoi - Converts a string to an integer
 * @s: string
 *
 * Return: integer
*/
int _atoi(char *s)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (s[0] == '-')
	{
		sign = -1;
		i++;
	}
	for (; s[i] != '\0'; i++)
	{
		result = result * 10 + (s[i] - '0');
	}

	return (sign * result);
}

/**
 * main - Entry point
 * @argc: count
 * @argv: vector
 *
 * Return: 0 or 1
*/
int main(int argc, char *argv[])
{
	int i, sum = 0;

	if (argc == 1)
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}
	for (i = 1; i < argc; i++)
	{
		if (!is_positive_number(argv[i]))
		{
			_putchar('E');
			_putchar('r');
			_putchar('r');
			_putchar('o');
			_putchar('r');
			_putchar('\n');
			return (1);
		}
		sum += _atoi(argv[i]);
	}

	print_number(sum);
	_putchar('\n');

	return (0);
}
