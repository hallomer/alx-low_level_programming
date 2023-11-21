#include "main.h"
#include <stdlib.h>

/**
 * strtow - splits a string into words
 * @str: string to be split
 *
 * Return: a pointer to an array of strings, or NULL if it fails
*/
char **strtow(char *str)
{
	char **words;
	int word_count = 0, i, j, k, len, start;

	if (str == NULL || *str == '\0')
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			word_count++;
	}
	words = malloc(sizeof(char *) * (word_count + 1));
	if (words == NULL)
		return (NULL);

	j = start = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
		{
			len = i - start + 2;
			words[j] = malloc(sizeof(char) * len);
			if (words[j] == NULL)
			{
				for (k = 0; k < j; k++)
					free(words[k]);
				free(words);
				return (NULL);
			}
			for (k = 0; k < len - 1; k++)
				words[j][k] = str[start + k];
			words[j][k] = '\0';
			j++;
			start = i + 1;
		}
		else if (str[i] == ' ')
			start++;
	}

	words[j] = NULL;
	return (words);
}
