#include "main.h"

/**
 * factorial - Return the factorial of a given number
 * @n: number
 *
 * Return: factorial of n, (-1) if n is negative and (1) if n is 0
*/

int factorial(int n)
{
	if (n < 0)
		return (-1);

	if (n == 0)
		return (1);

	return (n * factorial(n - 1));
}
