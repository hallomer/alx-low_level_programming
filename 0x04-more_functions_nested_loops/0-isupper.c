#include "main.h"

/**
 * _isupper - checks for uppercase character
 *
 * Return: 0*/

int _isupper(int c)
{
	int c;

	if (c >= 'A' || c <= 'Z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
