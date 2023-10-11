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
	unsigned char *code;
	size_t size, i;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	size = atoi(argv[1]);

	if (size < 0)
	{
		printf("Error\n");
		return (2);
	}

	code = (unsigned char *)main;

	for (i = 0; i < size; i++)
	{
		if (!(i % 2))
		{
			printf(" ");
		}

		printf("%02x", code[i]);
	}

	printf("\n");
	return (0);
}
