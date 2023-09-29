#include "main.h"

int _sqrt_helper(int n, int i);
/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: input number
 *
 * Return: square root of a number or -1
*/

int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	if (n == 0 || n == 1)
	{
		return (n);
	}
	return (_sqrt_helper(n, 1));
}

/**
 * _sqrt_helper - recursive helper function
 * @n: number
 * @i: the current divisor to check
 *
 * Return: The square root of the number or -1
*/

int _sqrt_helper(int n, int i)
{
	if (i * i == n)
	{
		return (i);
	}
	if (i * i > n)
	{
		return (-1);
	}
	return (_sqrt_helper(n, i + 1));
}
