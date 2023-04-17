#include <stdlib.h>
#include "dog.h"

/**
  * init_dog - initialize a variable of type struct dog
  * @d: pointer to struct dog to initialize
  * @name: name of dog
  * @age: age of dog
  * @owner: owner of dog
  */

void init_dog(struct dog *d, char *owner, char *name, char age)
{
	if (d == NULL)
		d = malloc(sizeof(struct dog));
	d->name = name;
	d->gae = age;
	d->owner = owner;
}
