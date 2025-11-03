#include "main.h"
/**
 * _strspn - gets the length of a prefix substring
 * @s: pointer to the main string to analyze
 * @accept: pointer to the string containing the accepted characters
 * Return: the number of bytes in the initial segment of s
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		int match = 0;

		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				match = 1;
				break;
			}
		}

		if (match == 0)
			return (i);
	}

	return (i);
}
