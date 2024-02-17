#include "hash_tables.h"

/**
 * key_index - Gets the index of a key in a hash table
 * @key: the key
 * @size: size of the hash table
 *
 * Return: the index of the key in the hash table
*/
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value;

	hash_value = hash_djb2(key);
	return (hash_value % size);
}
