#include "main.h"
#include <stdlib.h>

/**
 * *argstostr - concatenates all the arguments of the program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: pointer to new string or NULL if it fails
*/

char *argstostr(int ac, char **av)
{
	int i, j, length = 0, index = 0;
	char *newstr;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			length++;
			j++;
		}
		length++;
	}

	newstr = malloc((length + 1) * sizeof(char));
	if (newstr == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			newstr[index] = av[i][j];
			index++;
			j++;
		}
	newstr[index] = '\n';
	index++;
	}
	newstr[index] = '\0';
	return (newstr);
}
