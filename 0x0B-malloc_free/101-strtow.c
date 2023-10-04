#include "main.h"
#include <stdlib.h>

/**
 * count_words - counts the number of words in a string
 * @str: string
 *
 * Return: number of words
*/

int count_words(char *str)
{
	int count = 0, i = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

/**
 * allocate_words - allocates memory for the words array
 * @str: string
 * @word_count: number of words
 *
 * Return: allocated words array
*/

char **allocate_words(char *str, int word_count)
{
	char **words;
	int i, j, k, len;

	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			len = 0;
			k = i;
			while (str[k] != ' ' && str[k] != '\0')
			{
				len++;
				k++;
			}
			words[j] = malloc((len + 1) * sizeof(char));
			if (words[j] == NULL)
			{
				for (k = 0; k < j; k++)
					free(words[k]);
				free(words);
				return (NULL);
			}
			for (k = 0; k < len; k++)
				words[j][k] = str[i++];
			words[j][k] = '\0';
			j++;
		}
		else
			i++;
	}

	words[j] = NULL;
	return (words);
}

/**
 * strtow - splits a string into words
 * @str: string
 *
 * Return: pointer, or NULL if str is NULL or empty, or if it fails
*/
char **strtow(char *str)
{
	char **words;
	int word_count;

	if (str == NULL || *str == '\0')
	return (NULL);

	word_count = count_words(str);
	words = allocate_words(str, word_count);

	return (words);
}
