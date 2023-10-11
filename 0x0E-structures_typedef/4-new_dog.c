#include "dog.h"
#include <stdlib.h>

char *str_copy(char *src);

/**
 * *new_dog - creates a new dog object with the given name, age and owner
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the dog object, or NULL if memory allocation fails
*/

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog = malloc(sizeof(dog_t));

	if (new_dog == NULL)
	{
		return (NULL);
	}

	new_dog->name = str_copy(name);
	if (new_dog->name == NULL)
	{
		free(new_dog);
		return (NULL);
	}

	new_dog->age = age;

	new_dog->owner = str_copy(owner);
	if (new_dog->owner == NULL)
	{
		free(new_dog->name);
		free(new_dog);
		return (NULL);
	}
	return (new_dog);
}

/**
 * *str_copy- copies a string from source to destination
 * @src: source string
 *
 * Return: pointer to the copied string, or NULL if memory allocation fails
*/

char *str_copy(char *src)
{
	int leng, i;
	char *dest;

	if (src == NULL)
	{
		return (NULL);
	}

	leng = 0;
	while (src[leng] != '\0')
	{
		leng++;
	}

	dest = malloc((leng + 1) * sizeof(char));
	if (dest == NULL)
	{
		return (NULL);
	}

	for (i = 0; i <= leng; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
