#include "main.h"

/**
 * *_strncat - concatenates two strings
 * @dest: string 1
 * @src: string 2
 * @n: number to be copied
 *
 * Return: dest
*/

char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	{

	}
	for (j = 0; j < n && src[j] != '\0'; j++)
	{
		dest[i + j] = src[j];
	}
	dest[i + j] = '\0';
	return (dest);
}
