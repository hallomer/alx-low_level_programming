#include <stdlib.h>
#include "dog.h"

int _strlen(char *str);
char *_strcpy(char *dest, char *src);

/**
 * new_dog - A function that creates a new dog
 * @name: name of new dog
 * @age: age of new dog
 * @owner: owner of new dog
 *
 * Return: pointer to new dog or NULL if it fails
*/
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;

	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
		return (NULL);

	new_dog->name = malloc(_strlen(name) + 1);
	if (new_dog->name == NULL)
	{
		free(new_dog);
		return (NULL);
	}

	new_dog->owner = malloc(_strlen(owner) + 1);
	if (new_dog->owner == NULL)
	{
		free(new_dog->name);
		free(new_dog);
		return (NULL);
	}

	_strcpy(new_dog->name, name);
	new_dog->age = age;
	_strcpy(new_dog->owner, owner);

	return (new_dog);
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
