#include "main.h"

/**
 * _strlen_recursion - Returns the length of a string
 * @s: string
 *
 * Return: length of s
*/
int _strlen_recursion(char *s)
{
	int length = 0;

	if (*s == '\0')
	{
		return (0);
	}

	length = _strlen_recursion(s + 1);

	return (length + 1);
}
