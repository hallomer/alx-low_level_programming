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
	int i, j = 0, k, word_count = 0, word_length = 0;

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
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			word_length++;
			if (str[i + 1] == ' ' || str[i + 1] == '\0')
			{
				words[j] = malloc((word_length + 1) * sizeof(char));
				if (words[j] == NULL)
				{
					for (k = 0; k < j; k++)
						free(words[k]);
					free(words);
					return (NULL);
				}
				for (k = 0; k < word_length; k++)
					words[j][k] = str[i - word_length + k + 1];

				words[j][word_length] = '\0';
				word_length = 0;
				j++;
			}
		}
	}
	words[word_count] = NULL;
	return (words);
}
