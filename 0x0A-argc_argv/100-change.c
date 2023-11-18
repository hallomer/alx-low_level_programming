#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * main - Entry point for a program that prints the minimum num of coins needed
 * @argc: arguments count
 * @argv: array of arguments
 *
 * Return: 0 on success or 1 if error
*/
int main(int argc, char *argv[])
{
	int cents, coins = 0, i;
	int denom[] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	for (i = 0; i < 5; i++)
	{
		while (cents >= denom[i])
		{
			cents -= denom[i];
			coins++;
		}
	}

	printf("%d\n", coins);
	return (0);
}
