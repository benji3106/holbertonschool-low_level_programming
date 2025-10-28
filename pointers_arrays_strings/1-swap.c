#include "main.h"
/**
 * swap_int - function that swaps the value of two integers.
 * @a: first value of integer
 * @b: second value of integer
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
