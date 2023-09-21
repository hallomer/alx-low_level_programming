#include "main.h"

/**
 * *rot13 - encodes a string using rot13
 * @str: string to be encoded
 *
 * Return: str
*/

char *rot13(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M'))
		{
			str[i] += 13;
		}
		else ((str[i] >= 'm' && str[i] <= 'z') ||
			(str[i] >= 'M' && str[i] <= 'Z'))
		{
			str[i] -= 13;
		}
		i++;
	}
	return (str);
}
