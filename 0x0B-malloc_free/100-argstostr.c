#include "main.h"
#include <stdlib.h>

/**
 * *argstostr - Concatenates all the arguments of program
 * @ac: arguments count
 * @av: array of arguments
 * Return: pointer to a new string, or NULL if it fails
*/
char *argstostr(int ac, char **av)
{
	char *new_str, *str;
	int i, j, k, len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		str = av[i];
		j = 0;

		while (str[j++])
			len++;
		len++;
	}

	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);

	for (i = 0, j = 0; i < ac && j < len; i++)
	{
		str = av[i];
		k = 0;

		while (str[k])
		{
			new_str[j] = str[k];
			k++;
			j++;
		}
		new_str[j++] = '\n';
	}
	new_str[j] = '\0';

	return (new_str);
}
