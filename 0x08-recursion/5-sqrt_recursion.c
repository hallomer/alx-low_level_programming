#include "main.h"


int _sqrt(int n, int i);

/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: number
 *
 * Return: square of n, (-1) if n is negative
*/
int _sqrt_recursion(int n)
{
	return (_sqrt(n, 1));
}

/**
 * _sqrt - Performs the acutal calculation
 * @n: number
 * @i: current value
 *
 * Return: square of n
*/
int _sqrt(int n, int i)
{
	if (i * i == n)
		return (i);

	else if (i * i > n)
		return (-1);

	else
		return (_sqrt(i + 1, n));
}
