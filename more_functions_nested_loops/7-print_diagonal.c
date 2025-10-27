#include "main.h"
/**
 *print_diagonal - Program a function that draws a diagonal line.
 *@n: number of times the character \ should be printed
 */
void print_diagonal(int n)
{
	int i, d;

	if (n > 0)
	{
		for (i = 0; i < n; i++)
		{
			for (d = 0; d < i; d++)
			{
				_putchar(' ');
			}
				_putchar('\\');
				_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
