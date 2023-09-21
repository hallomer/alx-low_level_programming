#include "main.h"

/**
 * *leet - encodes a string into 1337
 * @str: a string
 *
 * Return: str
*/

char *leet(char *str)
{
	int i, j;
	char a[] = {'a', 'e', 'o', 't', 'l'};
	char n[] = {'4', '3', '0', '7', '1'};

	i = 0;

	while (str[i] != '\0')
	{
		j = 0;
		while (j < 5)
		{
			if (str[i] == a[j] || str[i] == a[j] - 32)
			{
				str[i] = n[j];
				break;
			}
			j++;
		}
		i++;
	}
	return (str);
}
