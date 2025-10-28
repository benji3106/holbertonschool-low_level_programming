#include "main.h"
/**
 * rev_string - prints a string, in reverse.
 * @s: the string to print
 * Return: nothing
 */
void rev_string(char *s)
{
	int i = 0;
	int j = 0;
	char temp;

	while (s[j] != '\0')
	{
		j++;
	}
	j--;

	while (i < j)
	{
	temp = s[i];
	s[i] = s[j];
	s[j] = temp;
	i++;
	j--;
	}
}
