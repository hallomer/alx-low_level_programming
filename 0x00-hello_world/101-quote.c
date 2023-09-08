#include <unistd.h>

/**
 * main - Entry point
 *
 * Description: a program that uses wtite function to print a qoute
 *
 * Return: 1 (fail)
*/

int main(void)
{
	char quo[] = " and that piece of art is useful\" - Dora Korpar, 2015-10-19 ";

	write(1, quo, 59);
	return (1);
}
