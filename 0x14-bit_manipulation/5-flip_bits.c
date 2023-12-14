#include "main.h"

/**
 * flip_bits - Filbs bits
 * @n: number
 * @m: modifed number
 *
 * Return: the number of bits needs to be fliped to get from n to m
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;
	unsigned int count = 0;

	while (xor_result > 0)
	{
		count += xor_result & 1;
		xor_result >>= 1;
	}

	return (count);
}
