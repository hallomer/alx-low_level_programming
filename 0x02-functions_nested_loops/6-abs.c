#include "main.h"

/**
 * _abs - compute the absolute value of an integer
 * @y: parameter to be checked
 *
 * Return: 0
*/

int _abs(int y)
{
	if (y < 0)
	{
		return (-y);
	}
	else
	{
		return (y);
	}
}
