#include "main.h"
#include <stdlib.h>

/**
 * *_strdup - returns a pointer to a newly allocated space in memory,
 *	which contains a copy of the string given
 * @str: string
 *
 * Return: a pointer or NULL if str = NULL or if insufficient memory
*/

char *_strdup(char *str)
{
	int length, i;
	char *newstr;

	if (str == NULL)
	{
		return (NULL);
	}

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}

	newstr = malloc((length + 1) * sizeof(char));

	if (newstr == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < length; i++)
	{
		newstr[i] = str[i];
	}
	newstr[i] = '\0';
	return (newstr);
}
