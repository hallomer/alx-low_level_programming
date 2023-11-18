#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry point for a program that adds positive numbers
 * @argc: arguments count
 * @argv: array of arguments
 *
 * Return: 0 on success or 1 if error
*/
int main(int argc, char *argv[])
{
	int i;
	unsigned int j, sum = 0;
	char *k;

	if (argc == 1)
	{
		printf("0\n");
	}

	for (i = 1; i < argc; i++)
	{
		k = argv[i];

		for (j = 0; j < strlen(k); j++)
		{
			if (k[j] < 48 || k[j] > 57)
			{
				printf("Error\n");
				return (1);
			}
		}
		sum += atoi(k);
		k++;
	}

	printf("%d\n", sum);

	return (0);
}
