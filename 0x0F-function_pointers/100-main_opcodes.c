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
	char *opcode;
	int size, i;

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

	opcode = (char *)main;

	for (i = 0; i < size; i++)
	{
		printf("%.2hhx", opcode[i]);
		if (i < size - 1)
		{
			printf(" ");
		}
	}
	printf("\n");
	return (0);
}
