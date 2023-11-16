#include "main.h"
#include <string.h>

int helper(char *start, char *end);

/**
 * is_palindrome - Checks if a string is a palindrome or not
 * @s: string to check
 *
 * Return: (1) if a string is a palindrome and (0) if not
*/
int is_palindrome(char *s)
{
	return (helper(s, s + strlen(s) - 1));
}

/**
 * helper - Checks if a string is a palindrome or not
 * @start: first character
 * @end: last character
 * 
 * Return: (1) if a string is a palindrome and (0) if not
*/
int helper(char *start, char *end)
{
	if (start >= end)
		return (1);

	if (*start != *end)
		return (0);

	return (helper(start + 1, end - 1));
}
