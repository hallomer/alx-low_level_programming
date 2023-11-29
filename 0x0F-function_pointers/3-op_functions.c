#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * op_add - Returns the sum of a and b
 * @a: num1
 * @b: num2
 *
 * Return: the sum
*/
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - Returns the difference of a and b
 * @a: num1
 * @b: num2
 *
 * Return: the difference
*/
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - Returns the product of a and b
 * @a: num1
 * @b: num2
 *
 * Return: the product
*/
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - Returns the result of division of a and b
 * @a: num1
 * @b: num2
 *
 * Return: the result of the division
*/
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a / b);
}

/**
 * op_mod - Returns the reminder of division of a and b
 * @a: num1
 * @b: num2
 *
 * Return: the reminder of the division
*/
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a % b);
}
