#include <stdio.h>

#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * main - prints the name of the file it was compiled from
 *
 * Return: 0 (success)
*/

int main(void)
{
	_putchar("%s\n", __FILE__);
	return (0);
}
