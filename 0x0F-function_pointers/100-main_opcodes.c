#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point, a program that prints the opcodes of its main function
 * @argc: argument count
 * @argv: array of arguments
 *
 * Return: 0 (success)
*/
int main(int argc, char *argv[])
{
	int num_of_bytes, i;
	unsigned char *opcode;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	num_of_bytes = atoi(argv[1]);

	if (num_of_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	opcode = (unsigned char *)main;

	for (i = 0; i < num_of_bytes; i++)
	{
		printf("%.2hhx", opcode[i]);

		if (i < num_of_bytes - 1)
			printf(" ");
	}

	printf("\n");
	return (0);
}
