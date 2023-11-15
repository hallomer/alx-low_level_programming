#include "main.h"


int _sqrt(int n, int start, int end);

/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: number
 *
 * Return: square of n, (n) if 0 or 1 and (-1) if n is negative
*/
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	if (n == 0 || n == 1)
		return (n);

	return (_sqrt(n, 1, n));
}

/**
 * _sqrt - Performs the actual calculation of the square root
 * @n: number
 * @start: starting point
 * @end: ending point
 *
 * Return: square of n or (-1) if not found
*/
int _sqrt(int n, int start, int end)
{
	int mid_point = (start + end) / 2;
	int square = mid_point * mid_point;

	if (start <= end)
	{
		if (square == n)
			return (mid_point);

		else if (square > n)
			return (_sqrt(n, start, mid_point - 1));

		else
			return (_sqrt(n, mid_point + 1, end));
	}

	return (-1);
}
