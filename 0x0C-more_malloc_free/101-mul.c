#include "main.h"
#include <stdlib.h>

/**
 * _strlen - Calculates the length of a string
 * @num: input string
 *
 * Return: length
*/
int _strlen(char *num)
{
	int length = 0;

	while (num[length] != '\0')
		length++;

	return (length);
}

/**
 * help_mul - Performs the actual multiplication
 * @num1: number1
 * @num2: number2
 * @result: array to store the result
 * @len1: length of num1
 * @len2: length of num2
 *
 * Return: void
*/
void help_mul(char *num1, char *num2, int *result, int len1, int len2)
{
	int carry = 0;
	int n1, n2, sum, start, i, j;

	for (i = 0; i < len1 + len2; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n1 = num1[i] - '0';

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = n1 * n2 + result[i + j + 1] + carry;
			result[i + j + 1] = sum % 10;
			carry = sum / 10;
		}

		result[i] += carry;
	}

	start = 0;
	while (start < len1 + len2 && result[start] == 0)
		start++;

	if (start == len1 + len2)
		_putchar('0');
	else
	{
		for (i = start; i < len1 + len2; i++)
			_putchar(result[i] + '0');
	}

	_putchar('\n');
}

/**
 * multiply - Multiplies two positive numbers
 * @num1: number1
 * @num2: number2
 *
 * Return: void
*/
void multiply(char *num1, char *num2)
{
	int len1 = _strlen(num1);
	int len2 = _strlen(num2);
	int *result;

	result = malloc(sizeof(int) * (len1 + len2));
	if (result == NULL)
	{
		exit(98);
	}

	help_mul(num1, num2, result, len1, len2);

	free(result);
	exit(0);
}

/**
 * is_digit - checks if a number is digit
 * @num: number to check
 *
 * Return: 1
*/
int is_digit(char *num)
{
	int i;

	for (i = 0; num[i] != '\0'; i++)
	{
		if (num[i] < '0' || num[i] > '9')
		{
			_putchar('E');
			_putchar('r');
			_putchar('r');
			_putchar('o');
			_putchar('r');
			_putchar('\n');
			exit(98);
		}
	}
	return (1);
}
/**
 * main - Entry point
 * @argc: arguments count
 * @argv: array of arguments
 *
 * Return: 0 (success)
*/
int main(int argc, char *argv[])
{
	char *num1, *num2;

	if (argc != 3)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}

	num1 = argv[1];
	num2 = argv[2];

	is_digit(num1);
	is_digit(num2);

	multiply(num1, num2);

	return (0);
}
