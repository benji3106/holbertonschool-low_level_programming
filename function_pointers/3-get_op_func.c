#include <stdio.h>
#include "3-calc.h"

/**
 * get_op_func - Selects the correct function to perform the operation
 * @s: The operator passed as argument
 *
 * Return: A pointer to the function that corresponds to the operator.
 *         Returns NULL if the operator is not valid.
 *
 * Description: This function uses a structure array to compare the operator
 *              passed by the user with the available operators. It returns
 *              the function associated with the matched operator.
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
	int i = 0;

	while (ops[i].op != NULL && ops[i].op[0] != s[0])
		i++;

	if (ops[i].op == NULL)
		return (NULL);

	return (ops[i].f);
}
