#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point for a program that adds positive numbers
 * @argc: arguments count
 * @argv: array of arguments
 *
 * Return: 0 on success or 1 if error
*/
int main(int argc, char *argv[])
{
	int i, j, sum = 0;

	if (argc == 1)
	{
		printf("0\n");
	}

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}
		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);

	return (0);
}
