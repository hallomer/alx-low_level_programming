#include "dog.h"
#include <stdlib.h>

int _strlen(char *str);
char *_strcpy(char *dest, char *src);

/**
 * init_dog -  Initialize a variable of type struct dog
 * @d: a pointer to a struct dog
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 *
 * Return: nothing
*/
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = malloc(_strlen(name) + 1);
	d->owner = malloc(_strlen(owner) + 1);

	_strcpy(d->name, name);

	d->age = age;

	_strcpy(d->owner, owner);
}

/**
 * _strlen - Calculates the length of a string
 * @str: string
 *
 * Return: length
*/
int _strlen(char *str)
{
	int length = 0;

	while (*str != '\0')
	{
		length++;
	}

	return (length);
}

/**
 * _strcpy - Copies content of src to dest
 * @dest: destination
 * @src: source
 *
 * Return: destination
*/
char *_strcpy(char *dest, char *src)
{
	int i;
	int length = _strlen(src);

	for (i = 0; i <= length; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
