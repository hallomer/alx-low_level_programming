#include "main.h"
#include <stdlib.h>

/**
 * *str_concat - makes new string contains s1 followed by s2
 * @s1: string1
 * @s2: string2
 *
 * Return: pointer to new string or NULL if it fails
*/
char *str_concat(char *s1, char *s2)
{
	char *concate;
	unsigned int len1 = 0;
	unsigned int len2 = 0;
	unsigned int i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	concate = malloc(sizeof(char) * (len1 + len2 + 1));

	if (concate == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		concate[i] = s1[i];
	for (j = 0; j <= len2; j++)
		concate[i + j] = s2[j];

	return (concate);
}
