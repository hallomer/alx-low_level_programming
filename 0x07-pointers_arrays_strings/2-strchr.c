#include "main.h"

/**
 * *_strchr - locates a charecter in a string
 * @s: string
 * @c: charecter to be located
 *
 * Return: pointer to the first occurrence of c or 0
*/

char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return (&s[i]);
		}
		i++;
	}
	return (0);
}
