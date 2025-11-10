#include <stdlib.h>

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 *
 * Return: pointer to new string, or NULL if str is NULL or malloc fails
 */
char *_strdup(char *str)
{
	char *copy;
	int len = 0, i;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	copy = malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		copy[i] = str[i];

	copy[len] = '\0';
	return (copy);
}
