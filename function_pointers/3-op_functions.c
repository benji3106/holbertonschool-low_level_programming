#include "3-calc.h"
#include <stdio.h>

/**
 * op_add - Adds two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: The result of a + b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - Subtracts two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: The result of a - b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - Multiplies two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: The result of a * b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - Divides two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: The result of a / b
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - Calculates the remainder of the division of two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: The result of a % b
 */
int op_mod(int a, int b)
{
	return (a % b);
}
