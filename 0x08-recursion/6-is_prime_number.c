#include "main.h"

int _is_prime_helper(int n, int i);

/**
 * is_prime_number - returns 1 if n is a prime number, otherwise return 0
 * @n: input number
 *
 * Return: 1 or 0
*/

int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}
	return (_is_prime_helper(n, 2));
}

/**
 * _is_prime_helper - recursive helper function
 * @n: input number
 * @i: divisor
 *
 * Return: 1 or 0
*/

int _is_prime_helper(int n, int i)
{
	if (i == n)
	{
		return (1);
	}
	if (n % i == 0)
	{
		return (0);
	}
	return (_is_prime_helper(n, i + 1));
}
