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
	if (n < 0)
		return (-1);

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
	int next_num;

	if (i * i == n)
		return (i);

	else if (i * i > n)
		return (-1);

	next_num = _sqrt(n, i + 1);

	if (next_num > 0)
		return (next_num);

	return (i);
}
