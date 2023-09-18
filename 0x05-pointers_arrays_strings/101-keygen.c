#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10

/**
 * main - enerates random valid passwords the program 101-crackme
 *
 * Return: 0
*/

int main(void)
{
	int sum;
	char c;

	srand(time(NULL));

	while (sum <= 2645)
	{
		c = rand() % 128;
		sum += c;
		putchar(c);
	}
	putchar(2772 - sum);
	return (0);
}
