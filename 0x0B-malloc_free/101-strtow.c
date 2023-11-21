#include "main.h"
#include <stdlib.h>

/**
 * str_len - Gets the length of a string
 * @str: string
 *
 * Return: length
 */

int str_len(char *str)
{
	int len = 0;

	while (*str && *str != ' ')
	{
		len++;
		str++;
	}
	return (len);
}

/**
 * word_count - Counts the number of words in a string
 * @str: string
 *
 * Return: the number of words
 */
int word_count(char *str)
{
	int words = 0, len = 0, i = 0;

	while (str[len])
	{
		len++;
	}

	while (i < len)
	{
		if (str[i] != ' ')
		{
			words++;
			i += str_len(str + i);
		}
		else
			i++;

	}

	return (words);
}

/**
 * **strtow - Splits a string into words
 * @str: the string to be split
 *
 * Return: pointer to an array of words or NULL if it fails
 */
char **strtow(char *str)
{
	int words, w = 0, letters, i, j;
	char **strings;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	words = word_count(str);
	if (words == 0)
		return (NULL);
	strings = malloc(sizeof(char *) * (words + 1));
	if (strings == NULL)
		return (NULL);

	while (*str)
	{
		if (*str != ' ')
		{
			letters = str_len(str);
			strings[w] = malloc(sizeof(char) * (letters + 1));
			if (strings[w] == NULL)
			{
				for (i = 0; i < w; i++)
				{
					for (j = 0; j < str_len(strings[i]); j++)
						free(strings[i] + j);
					free(strings[i]);
				}
				free(strings);
				return (NULL);
			}
			for (i = 0; i < letters; i++)
				strings[w][i] = str[i];
			strings[w][letters] = '\0';
			w++;
			str += letters;
		}
		else
			str++;
	}
	strings[w] = NULL;
	return (strings);
}
