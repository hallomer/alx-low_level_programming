#include "main.h"
#include <stdlib.h>

/**
 * _isdigit - checks if a character is a digit
 * @c: character
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */
int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - calculates the length of a string
 * @str: string
 *
 * Return: length of string
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;

	return (len);
}

/**
 * mul - multiplies two positive numbers
 * @num1: first number
 * @num2: second number
 */
void mul(char *num1, char *num2)
{
	int len1, len2, len, i, j, carry, digit;
	int *result;

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	len = len1 + len2;
	result = malloc(sizeof(int) * len);
	if (result == NULL)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}
	for (i = 0; i < len; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			digit = (num1[i] - '0') * (num2[j] - '0') + carry + result[i + j + 1];
			carry = digit / 10;
			result[i + j + 1] = digit % 10;
		}
		result[i] += carry;
	}
	i = 0;
	while (i < len - 1 && result[i] == 0)
		i++;

	for (; i < len; i++)
		_putchar(result[i] + '0');

	_putchar('\n');
	free(result);
}

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: array of argument strings
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int i, j;

	if (argc != 3)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		return (98);
	}

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j]; j++)
		{
			if (!_isdigit(argv[i][j]))
			{
				_putchar('E');
				_putchar('r');
				_putchar('r');
				_putchar('o');
				_putchar('r');
				_putchar('\n');
				return (98);
			}
		}
	}

	mul(argv[1], argv[2]);

	return (0);
}
