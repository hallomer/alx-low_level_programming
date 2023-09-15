#include <stdio.h>
#include <math.h>
/**
 * main - prints the largest prime factor of the number 612852475143
 *
 * Return: 0
*/
int main(void)
{
	long number = 612852475143;
	long largestFactor = -1;
	long i;

	while (number % 2 == 0)
	{
		largestFactor = 2;
		number /= 2;
	}
	for (i = 3; i <= sqrt(number); i += 2)
	{
		while (number % i == 0)
		{
			largestFactor = i;
			number /= i;
		}
	}
	if (number > 2)
	{
		largestFactor = number;
	}
	printf("%ld\n", largestFactor);
	return (0);
}
