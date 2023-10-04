#include <stdlib.h>
#include "main.h"

/**
 * count_words - count the number of words in a string
 * @s: string
 *
 * Return: number of words
*/
int count_words(char *s)
{
	int in_word, c, words;

	in_word = 0;
	words = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			words++;
		}
	}

	return (words);
}

/**
 * **strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer or NULL if it fails
*/
char **strtow(char *str)
{
	char **newstr, *tmp;
	int i, k = 0, len = 0, words, c = 0, start, end;

	while (*(str + len))
		len++;
	words = count_words(str);
	if (words == 0)
		return (NULL);

	newstr = (char **) malloc(sizeof(char *) * (words + 1));
	if (newstr == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				end = i;
				tmp = (char *) malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				newstr[k] = tmp - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	newstr[k] = NULL;

	return (newstr);
}
