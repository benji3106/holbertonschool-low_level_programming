#include "dog.h"
#include <stdio.h>

/**
 * print_dog - displays a dog's information
 * @d: pointer to the structure to display
 */
void print_dog(struct dog *d);
{
	if (d == NULL)
		return;

	if (d->name == NULL)
		printf("Name: (nil)\n");
	else
		printf("Name: %s\n", d->name);

	printf("Age: %f\n", d->age);

	if (d->owner == NULL)
		printf("Owner: (nill\n)");
	else
		printf("Owner: %s\n", d->owner);
}
