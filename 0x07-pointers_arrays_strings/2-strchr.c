#include "main.h"
#include <stddef.h>
/**
 * *_strchr - locates a charecter in a string
 * @s: string
 * @c: charecter to be located
 *
 * Return: pointer to the first occurrence of c or NULL
*/

char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	return (NULL);
}
