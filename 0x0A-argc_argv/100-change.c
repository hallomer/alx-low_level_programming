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
	int cents, i;
	int coins[] = {25, 10, 5, 2, 1};
	int num_coins;
	int coin_count = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	for (i = 0; argv[1][i] != '\0'; i++)
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
		{
			printf("Error\n");
			return (1);
		}
	}
	cents = atoi(argv[1]);


	num_coins = sizeof(coins) / sizeof(coins[0]);

	for (i = 0; i < num_coins; i++)
	{
		coin_count += cents / coins[i];
		cents %= coins[i];
	}

	printf("%d\n", coin_count);
	return (0);
}
