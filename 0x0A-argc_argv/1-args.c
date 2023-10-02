#include "main.h"

/**
 * main - program that prints number of arguments passed into it
 * @argc: count
 * @argv: vector
 *
 * Return: 0
*/

int main(int argc, char *argv[])
{
	(void)argv;

	_putchar((argc - 1)+ '0');
	_putchar('\n');
	return (0);
}
