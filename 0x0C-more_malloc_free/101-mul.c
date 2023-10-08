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
 * _puts - prints a string
 * @str: string to print
 *
 * Return: void
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * *allocate_memory - allocates memory for a string
 * @size: size of a string
 *
 * Return: a pointer to allocated memory
*/
char *allocate_memory(int size)
{
	char *ptr = malloc((size + 1) * sizeof(char));

	if (ptr == NULL)
	{
		_puts("Error");
		exit(1);
	}
	return (ptr);
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
	int num1, num2, mul, leng = 0, i, temp;
	char *result;

	if (argc != 3 || !_atoi(argv[1]) || !_atoi(argv[2]))
	{
		_puts("Error");
		exit(98);
	}

	num1 = _atoi(argv[1]);
	num2 = _atoi(argv[2]);

	if (num1 <= 0 || num2 <= 0)
	{
		_puts("Error");
		exit(98);
	}

	mul = num1 * num2;

	temp = mul;
	while (temp != 0)
	{
		temp /= 10;
		leng++;
	}
	result = allocate_memory(leng);

	for (i = leng - 1; i >= 0; i--)
	{
		result[i] = (mul % 10) + '0';
		mul /= 10;
	}

	result[leng - 1] = '\0';

	_puts(result);
	_putchar('\n');
	free(result);
	return (0);
}
