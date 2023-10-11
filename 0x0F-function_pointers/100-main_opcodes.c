#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point, program that prints the opcodes of its own main function
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 (success)
*/
int main(int argc, char *argv[])
{
	char *code = (char *) main;
	size_t size, i;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	size = atoi(argv[1]);

	if (size < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (i = 0; i < size; i++)
	{
		printf("%02x", code[i] & 0xFE);

		if (i != size - 1)
		{
			printf(" ");
		}
	}

	printf("\n");
	return (0);
}
