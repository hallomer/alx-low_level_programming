#include "main.h"
#include <stdlib.h>

/**
 * *string_nconcat - Concatenates two strings
 * @s1: string1
 * @s2: string2
 * @n: number of bytes from s2 to concate
 *
 * Return: pointer or NULL if it fails
*/
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = 0, len2 = 0, concat_len = 0, i, j;
	char *new_str;

	if (s1 != NULL)
	{
		while (s1[len1] != '\0')
		{
			len1++;
		}
	}

	if (s2 != NULL)
	{
		while (s2[len2] != '\0')
		{
			len2++;
		}
	}

	if (n >= len2)
		n = len2;

	concat_len = len1 + n;

	new_str = malloc(concat_len + 1);
	if (new_str == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
	{
		new_str[i] = s1[i];
	}

	for (j = 0; j < n; j++)
	{
		new_str[i + j] = s2[j];
	}

	new_str[i + j] = '\0';
	return (new_str);
}
