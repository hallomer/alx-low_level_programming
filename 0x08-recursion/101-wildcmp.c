#include "main.h"

/**
 * helper - Compares two strings
 * @s1: string1
 * @s2: string2
 *
 * Return: (1) if the strings can be considered identical, otherwise (0)
*/
int helper(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s1 == '\0' || *s2 == '\0')
		return (0);

	if (*s1 == *s2)
		return (helper(s1 + 1, s2 + 1));

	return (helper(s1 + 1, s2));
}

/**
 * wildcmp - Compares two strings
 * @s1: string1
 * @s2: string2
 *
 * Return: (1) if the strings can be considered identical, otherwise (0)
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
		return (helper(s1, s2 + 1));

	if (*s1 == '\0' && *s2 == '\0') 
		return (1);

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
