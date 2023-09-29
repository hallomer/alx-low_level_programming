#include "main.h"

/**
 * wildcmp_rec - compares two strings
 * @s1: string1
 * @s2: string that can contain '*'
 * Return: 1 if match or 0
*/

int wildcmp_rec(char *s1, char *s2)
{
	if (*s2 == '\0')
	{
		return (*s1 == '\0');
	}
	if (*s2 == '*')
	{
		return (wildcmp_rec(s1, s2 + 1) ||
			(*s1 != '\0' && wildcmp_rec(s1 + 1, s2)));
	}
	if (*s1 == *s2 || *s2 == '?')
	{
		return (wildcmp_rec(s1 + 1, s2 + 1));
	}
	return (0);
}
/**
 * wildcmp - Entry point, calls the recursive helper function
 * @s1: string1
 * @s2: string2
 *
 * Return: 1 or 0
*/

int wildcmp(char *s1, char *s2)
{
	return (wildcmp_rec(s1, s2));
}
