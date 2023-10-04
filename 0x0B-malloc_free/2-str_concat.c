#include "main.h"
#include <stdlib.h>

/**
 * *str_concat - concatenates two strings
 * @s1: string1
 * @s2: string2
 *
 * Return: pointer or NULL in failure
*/

char *str_concat(char *s1, char *s2)
{
	unsigned int length1 = 0, length2 = 0, i, j;
	char *newstr;

	if (s1 != NULL)
	{
		while (s1[length1])
		{
			length1++;
		}
	}

	if (s2 != NULL)
	{
		while (s2[length2])
		{
			length2++;
		}
	}

	newstr = malloc(sizeof(char) * (length1 + length2 + 1));

	if (newstr == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < length1; i++)
	{
		newstr[i] = s1[i];
	}

	for (j = 0; j < length2; j++)
	{
		newstr[i + j] = s2[j];
	}

	newstr[i + j] = '\0';

	return (newstr);
}
