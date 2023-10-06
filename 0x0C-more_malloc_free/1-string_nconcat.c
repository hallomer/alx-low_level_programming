#include "main.h"
#include <stdlib.h>

/**
 * _strlen - calculate length of a string
 * @s: string
 *
 * Return: length
*/
unsigned int _strlen(char *s)
{
	unsigned int i = 0, leng;

	while (s[i] != '\0')
	{
		leng++;
		i++;
	}
	return (leng);
}

/**
 * *string_nconcat - concatenates two strings
 * @s1: string1
 * @s2: string2
 * @n: number of character to be concat
 * Return: a pointer to allocated memory or NULL
*/

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int leng1, leng2, i, theLeng;
	char *concat;

	if (s1 == NULL)
		s1 = " ";

	if (s2 == NULL)
		s2 = " ";

	leng1 = _strlen(s1);
	leng2 = _strlen(s2);
	if (n >= leng2)
		theLeng = leng1 + leng2;

	else
		theLeng = leng1 + n;

	concat = malloc((theLeng + 1) * sizeof(char));
	if (concat == NULL)
		return (NULL);

	i = 0;
	while (s1[i] != '\0')
	{
		concat[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0' && i < n)
	{
		concat[leng1 + i] = s2[i];
		i++;
	}
	concat[theLeng + i] = '\0';
	return (concat);
}
