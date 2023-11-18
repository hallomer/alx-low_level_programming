#include <stdio.h>

/**
 * main - Entry point for a program that prints number of its arguments
 * @argc: arguments count
 * @argv: array of arguments
 *
 * Return: 0
*/
int main(int argc, char *argv[])
{
	(void)argv;

	printf("%d\n", argc - 1);
	return (0);
}
