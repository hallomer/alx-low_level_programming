#include "calc.h"

/**
 * get_op_func - Selects the correct function to perform the operation
 * @s: the operator passed as argument
 *
 * Return: a pointer to a function or NULL if no match
*/
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	while (ops[i].op != NULL)
	{
		if (*(ops[i] == *s) && *(s + 1) == '\0')
		{
			return (ops[i].f);
		}
	}

	return (NULL);
}
