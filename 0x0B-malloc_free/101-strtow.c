#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int count_words(char *str);
char **allocate_words_array(int count);
void free_words_array(char **words, int count);
void extract_words(char *str, char **words);

/**
 * strtow - splits a string into words
 * @str: string to be split
 *
 * Return: a pointer to an array of strings, or NULL if it fails
 */
char **strtow(char *str)
{
	char **words;
	int word_count, onlySpaces = 1, i;

	if (str == NULL || *str == '\0')
		return (NULL);

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			onlySpaces = 0;
			break;
		}
	}

	if (onlySpaces)
		return (NULL);

	word_count = count_words(str);
	if (word_count == 0)
		return (NULL);

	words = allocate_words_array(word_count);
	if (words == NULL)
		return (NULL);

	extract_words(str, words);

	return (words);
}

/**
 * count_words - counts the number of words in a string
 * @str: input string
 *
 * Return: number of words
 */
int count_words(char *str)
{
	int count = 0, i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			count++;
	}

	return (count);
}

/**
 * allocate_words_array - allocates memory for the array of words
 * @count: number of words
 *
 * Return: pointer to the allocated array
 */
char **allocate_words_array(int count)
{
	char **words;

	words = (char **)malloc((count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	return (words);
}

/**
 * free_words_array - frees the memory allocated for the array of words
 * @words: array of words
 * @count: number of words
 */
void free_words_array(char **words, int count)
{
	int i;

	for (i = 0; i < count; i++)
		free(words[i]);

	free(words);
}

/**
 * extract_words - extracts words from the input string
 * @str: input string
 * @words: array of words
 */
void extract_words(char *str, char **words)
{
	int count = 0, start = 0, end = 0, i, j;

	for (i = 0; str[i]; i++)
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
				free_words_array(words, count);
				return;
			}

			for (j = 0; j < end - start; j++)
				words[count][j] = str[start + j];
			words[count][j] = '\0';
			count++;
		}
	}

	words[count] = NULL;
}
