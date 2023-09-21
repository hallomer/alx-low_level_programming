#include "main.h"

/**
 * *infinite_add - adds two numbers stored as strings
 * @n1: string1
 * @n2: string2
 * @r: result
 * @size_r: The size of the buffer
 *
 * Return: Pointer or 0
*/

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int carry = 0;
	int len1 = 0;
	int len2 = 0;
	int i, j, k;

	while (n1[len1] != '\0')
		len1++;
	while (n2[len2] != '\0')
		len2++;
	if (len1 + 2 > size_r || len2 + 2 > size_r)
		return (0);

	i = len1 - 1;
	j = len2 - 1;
	k = size_r - 1;
	r[k] = '\0';
	while (i >= 0 || j >= 0 || carry != 0)
	{
		int sum = carry;

		if (i >= 0)
			sum += n1[i] - '0';
		if (j >= 0)
			sum += n2[j] - '0';

	carry = sum / 10;
	sum = sum % 10;
	r[--k] = sum + '0';

	i--;
	j--;
	}
	if (carry != 0)
	{
		if (k == 0)
			return (0);

		r[--k] = carry + '0';
	}
	return (&r[k]);
}
