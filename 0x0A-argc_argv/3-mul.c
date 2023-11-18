#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point for a program that multiplies 2 numbers
 * @argc: arguments count
 * @argv: array of arguments
 *
 * Return: 0 on success or 1 if error
*/
int main(int argc, char *argv[])
{
	int n1, n2;

	if (argc != 3)
	{
		printf("Error\n");

		return (1);
	}

	n1 = atoi(argv[1]);
	n2 = atoi(argv[2]);

	printf("%d\n", n1 * n2);

	return (0);
}
