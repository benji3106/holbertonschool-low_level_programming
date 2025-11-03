#include "main.h"
/**
 * _strchr - fills memory with a constant byte
 * @s: pointer to the string to search
 * @c: character to find
 * Return: pointer to the first occurrence of c in s, or 0 if not found
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			return (&s[i]);
		}
	}

	if (c == '\0')
		return (&s[i]);

	return (0);
}
