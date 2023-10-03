#include "main.h"

/**
 * main - a program that prints all arguments
 * @argc: count
 * @argv: vector
 *
 * Return: 0
*/

int main(int argc, char *argv[])
{
	int i, j;

	for (i = 0 ; i < argc ; i++)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			_putchar(argv[i][j]);
			j++;
		}
		_putchar('\n');
	}
	return (0);
}
