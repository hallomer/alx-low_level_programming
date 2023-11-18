#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point for a program that prints the minimum num of coins needed
 * @argc: arguments count
 * @argv: array of arguments
 *
 * Return: 0 on success or 1 if error
*/
int main(int argc, char *argv[])
{
	int cents, coins = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);
	if (cents < 0)
		printf("0\n");

	while (cents > 0)
	{
		if (cents >= 25)
		{
			cents -= 25;
			coins++;
		}
		else if (cents >= 10)
		{
			cents -= 10;
			coins++;
		}
		else if (cents >= 5)
		{
			cents -= 5;
			coins++;
		}
		else if (cents >= 1)
		{
			cents -= 1;
			coins++;
		}
	}
	printf("%d\n", coins);
	return (0);
}
