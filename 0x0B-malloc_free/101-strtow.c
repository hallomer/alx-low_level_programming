#include "main.h"
#include <stdlib.h>

/**
 * count - count words
 * @str: string
 *
 * Return: word count
*/
int count(char *str)
{
	int word_count = 0;
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			word_count++;
	}

	return (word_count);
}

/**
 * **allocate - memory allocation
 * @word_count: size to allocated memory for
 *
 * Return: pointer
*/
char **allocate(int word_count)
{
	char **words = (char **)malloc(sizeof(char *) * (word_count + 1));

	return (words);
}

/**
 * *extract - extractes word
 * @str: string
 * @start: start of word
 * @end: end of word
 *
 * Return: pointer
*/
char *extract(char *str, int start, int end)
{
	int len = end - start + 1, i, j = 0;
	char *word = (char *)malloc(sizeof(char) * (len + 1));

	if (word == NULL)
		return (NULL);


	for (i = start; i <= end; i++)
	{
		word[j] = str[i];
		j++;
	}

	word[j] = '\0';
	return (word);
}

/**
 * *trim_spaces - trims trailing spaces
 * @word: word to trim
 *
 * Return: pointer
*/
char *trim_spaces(char *word)
{
	int len = 0, i;

	while (word[len] != '\0')
		len++;

	i = len - 1;

	while (i >= 0 && word[i] == ' ')
		i--;

	word[i + 1] = '\0';

	return (word);
}

/**
 * strtow - splits a string into words
 * @str: string to be split
 *
 * Return: a pointer to an array of strings, or NULL if it fails
*/
char **strtow(char *str)
{
	int word_count, i, j = 0, start = 0;
	char **words;

	if (str == NULL || *str == '\0')
		return (NULL);

	word_count = count(str);
	words = allocate(word_count);

	if (words == NULL)
		return (NULL);

	while (str[start] == ' ')
		start++;

	for (i = start; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;

			if (str[i] != '\0')
			{
				words[j] = extract(str, start, i - 1);
				words[j] = trim_spaces(words[j]);
				j++;
				start = i;
			}
		}
	}

	if (start < i)
	{
		words[j] = extract(str, start, i - 1);
		words[j] = trim_spaces(words[j]);
		j++;
	}
	words[j] = NULL;
	return (words);
}
