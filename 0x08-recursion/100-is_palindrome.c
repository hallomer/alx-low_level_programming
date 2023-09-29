#include "main.h"

int _strlen_recursion(char *s);
int check_palindrome(char *s, int start, int end);

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: string
 *
 * Return: 1 or 0
*/

int is_palindrome(char *s)
{
	int len = _strlen_recursion(s);

	if (len <= 1)
	{
		return (1);
	}
	return (check_palindrome(s, 0, len - 1));
}

/**
 * _strlen_recursion - return the length of a string
 * @s: string
 *
 * Return: length of s
*/

int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	return (1 + _strlen_recursion(s + 1));
}

/**
 * check_palindrome - helper function for checking palindrome
 * @s: string
 * @start: starting index
 * @end: ending index
 *
 * Return: 1 or 0
*/

int check_palindrome(char *s, int start, int end)
{
	if (start >= end)
	{
		return (1);
	}
	if (s[start] != s[end])
	{
		return (0);
	}
	return (check_palindrome(s, start + 1, end - 1));
}
