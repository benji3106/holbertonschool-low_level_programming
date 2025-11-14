#include "dog.h"
#include <stdlib.h>

/**
 * _strlen - retourne la longueur d'une chaîne
 * @s: chaîne
 * Return: longueur
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}
/**
 * _strcpy - copie une chaîne dans une autre
 * @dest: destination
 * @src: source
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';
	return (dest);
}
/**
 * new_dog - crée un nouveau chien
 * @name: nom du chien
 * @age: âge du chien
 * @owner: propriétaire du chien
 * Return: pointeur vers dog_t, ou NULL en cas d’erreur
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	int name_len, owner_len;

	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);

	name_len = _strlen(name);
	owner_len = _strlen(owner);

	d->name = malloc(sizeof(char) * (name_len + 1));
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}

	d->owner = malloc(sizeof(char) * (owner_len + 1));
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}

	_strcpy(d->name, name);
	_strcpy(d->owner, owner);
	d->age = age;

	return (d);
}
