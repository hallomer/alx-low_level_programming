#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: The string to be converted
 *
 * Return: The converted integer
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
		if (!is_digit(s[i]))
		{
			return (0);
		}
		result = result * 10 + (s[i] - '0');
	}

	return (sign * result);
}
/**
 * print_number - Prints an integer to the standard output (stdout)
 * @n: The integer to be printed
 *
 * Return: void
*/
void print_number(int n)
{
	int num_digits = 0;
	int temp = n;
	int divisor;
	int digit;


	if (n < 0)
	{
	_putchar('-');
	n = -n;
	}

	while (temp != 0)
	{
	temp /= 10;
	num_digits++;
	}

	if (num_digits == 0)
	{
		_putchar('0');
	}
	else
	{
		divisor = 1;
		while (num_digits > 1)
		{
			divisor *= 10;
			num_digits--;
		}

		while (divisor != 0)
		{
			digit = n / divisor;
			_putchar(digit + '0');
			n %= divisor;
			divisor /= 10;
		}
	}
}
/**
 * is_digit - Checks if a character is a digit
 * @c: The character to be checked
 *
 * Return: 1 if the character is a digit, 0 otherwise
*/
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of strings representing the command-line arguments
 *
 * Return: 0 on success, 1 on error
*/
int main(int argc, char *argv[])
{
	int i, num, sum = 0;

	if (argc == 1)
	{
		_putchar('0');
		_putchar('\n');
	return (0);
	}

	for (i = 1; i < argc; i++)
	{
		num = _atoi(argv[i]);
	if (num == 0 && !is_digit(argv[i][0]))
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		return (1);
	}
	sum += num;
	}
	print_number(sum);
	_putchar('\n');
	return (0);
}
