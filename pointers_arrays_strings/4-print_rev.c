#include "main.h"
/**
 * print_rev - prints a string, in reverse.
 * @s: the string to print
 * Return: nothing
 */
void print_rev(char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}

	while (length > 0)
	{
	_putchar(s[length - 1]);
	length--;
	}
	_putchar('\n');
}
