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
	int i = 0;

	while (str[i] == ' ')
		i++;

	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			word_count++;

			while (str[i] != ' ' && str[i] != '\0')
				i++;
		}
		else
			i++;
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
	int len = 0, i, word_length, j;
	char *trimmed_word;

	while (word[len] != '\0')
		len++;

	i = len - 1;

	while (i >= 0 && word[i] == ' ')
		i--;

	word_length = i + 1;

	trimmed_word = malloc((word_length + 1) * sizeof(char));

	if (trimmed_word == NULL)
		return (NULL);

	for (j = 0; j < word_length; j++)
		trimmed_word[j] = word[j];

	trimmed_word[word_length] = '\0';
	return (trimmed_word);
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
