#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Data of dogs
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 *
 * A struct to organize data of dogs
*/
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

typedef struct dog dog_t;

dog_t *new_dog(char *name, float age, char *owner);

#endif
