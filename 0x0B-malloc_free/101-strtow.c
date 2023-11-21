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
	int i, j, count = 0, start = 0, end = 0;
	char **words;

	if (str == NULL || *str == '\0')
		return (NULL);
	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			count++;
	}
	words = (char **)malloc((count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	i = count = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			start = i;
			while (str[i] && str[i] != ' ')
				i++;
			end = i;
			words[count] = (char *)malloc((end - start + 1) * sizeof(char));
			if (words[count] == NULL)
			{
				for (j = 0; j < count; j++)
					free(words[j]);
				free(words);
				return (NULL);
			}
			for (j = 0; j < end - start; j++)
				words[count][j] = str[start + j];
			words[count][j] = '\0';
			count++;
		}
		else
			i++;
	}
	words[count] = NULL;
	return (words);
}
