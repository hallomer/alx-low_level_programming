#include "main.h"

/**
 * *rot13 - encodes a string using rot13
 * @str: string to be encoded
 *
 * Return: str
*/

char *rot13(char *str)
{
	int i, j;
	char *input = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *output = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (input[j] != '\0')
		{
			if (str[i] == input[j])
			{
				str[i] = output[j];
				break;
			}
			j++;
		}
		i++;
	}
	return (str);
}
