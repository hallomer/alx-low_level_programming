#include "main.h"
#include <stdlib.h>

/**
 * *str_concat - function that concatenates two strings
 * @s1: string1
 * @s2: string2
 *
 * Return: pointer or NULL in failure
*/

char *str_concat(char *s1, char *s2)
{
	char *newstr;
	int i, j, k;

	if (s1 == NULL)
	{
		s1 = " ";
	}
	if (s2 == NULL)
	{
		s2 = " ";
	}

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		j++;
	}

	newstr = malloc((i + j + 1) * sizeof(char));

	if (newstr == NULL)
	{
		return (NULL);
	}

	for (k = 0; k < i; k++)
	{
		newstr[k] = s1[k];
	}
	for (k = 0; k < j; k++)
	{
		newstr[i + k] = s2[k];
	}
	newstr[i + j] = '\0';
	return (newstr);
}
