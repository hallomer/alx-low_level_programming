#include "main.h"
#include <stdlib.h>

/**
 * is_digit - checks if a character is a digit
 * @c: character
 *
 * Return: 1 if the character is a digit, 0 otherwise
*/
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _atoi - converts a string to an integer
 * @s: string
 *
 * Return: integer
*/
int _atoi(char *s)
{
	int result = 0;
	int i = 0;

	while (s[i] != '\0')
	{
		if (is_digit(s[i]))
		{
			result = result * 10 + (s[i] - '0');
		}
		else
		{
			return (0);
		}
		i++;
	}
	return (result);
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
	_putchar((n % 10) + '0');
}
/**
 * multiply - multiplies two positive numbers
 * @num1: first number
 * @num2: seconed number
 *
 * Return: result
*/
int multiply(int num1, int num2)
{
	return (num1 * num2);
}

/**
 * main - multiplies two positive numbers
 * @argc: count
 * @argv: vector
 *
 * Return: integer
*/
int main(int argc, char *argv[])
{
	int num1, num2, mul;

	if (argc != 3 || !_atoi(argv[1]) || !_atoi(argv[2]))
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}

	num1 = _atoi(argv[1]);
	num2 = _atoi(argv[2]);
	mul = multiply(num1, num2);

	print_number(mul);
	_putchar('\n');

	return (0);
}
