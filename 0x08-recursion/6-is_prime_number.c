#include  "main.h"

int is_prime(int i, int n);

/**
 * is_prime_number - Checks if the input integer is a prime number or not
 * @n: input integer
 *
 * Return: (1) if n is prime number, otherwise return (0)
*/
int is_prime_number(int n)
{
	if (n < 2)
		return (0);

	return (is_prime(2, n));
}
/**
 * is_prime - Does the acutal calculation
 * @n: number to check
 * @i: current divisor
 *
 * Return: (1) if n is prime number, otherwise return (0)
*/
int is_prime(int i, int n)
{
	if (i >= n)
		return (1);

	if (n % i == 0)
		return (0);

	return (is_prime(i + 1, n));
}
