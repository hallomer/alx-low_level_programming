#include <stdio.h>

/**
 * main - Entry point foa a program that prints its name
 * @argc: arguments count
 * @argv: array of arguments
 *
 * Return: 0
*/

int main(int argc, char *argv[])
{
	(void)argc;

	printf("%s\n", argv[0]);
	return (0);
}
