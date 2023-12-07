#include <stdio.h>

void print_first(void) __attribute__((constructor));

/**
 * print_first - Prints the required message before the main function is executed
 *
 * Return: nothing
 */
void print_first(void)
{
	printf("You're beat! and yet, you must allow,\nI bore my house upon my back!\n");
}
