#include "3-calc.h"

/**
 * op_add - add two numbers
 * @a: first number
 * @b: second number
 *
 * Return: the sum of a and b
*/
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subtract two numbers
 * @a: first number
 * @b: second number
 *
 * Return:  the difference of a and b
*/
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multplies two numbers
 * @a: first number
 * @b: second number
 *
 * Return: the product of a and b
*/
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - divid two numbers
 * @a: first number
 * @b: second number
 *
 * Return: result of the division of a by b
*/
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - get the modulo
 * @a: first number
 * @b: second number
 *
 * Return: the remainder of the division of a by b
*/
int op_mod(int a, int b)
{
	return (a % b);
}
