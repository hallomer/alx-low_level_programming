#include "main.h"
#include <stdlib.h>

/**
 * *_strdup - copies the string given as a parameter
 * @str: string
 *
 * Return: a pointer to the duplicated string, or NULL if it fails
*/
char *_strdup(char *str)
{
	char *duplicate;
	unsigned int len = 0;
	unsigned int i;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	duplicate = malloc(sizeof(char) * (len + 1));

	if (duplicate == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		duplicate[i] = str[i];

	return (duplicate);
}
