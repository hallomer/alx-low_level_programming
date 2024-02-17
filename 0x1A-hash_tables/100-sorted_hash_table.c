#include "hash_tables.h"

/**
 * shash_table_create - Create a new sorted hash table
 * @size: size of the hash table
 *
 * Return: the newly created hash table, or NULL if it fails
*/
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht = malloc(sizeof(shash_table_t));

	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	memset(ht->array, 0, sizeof(shash_node_t *) * size);
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Insert a key-value pair into the sorted hash table
 * @ht: hash table
 * @key: key
 * @value: value to insert
 *
 * Return: 1 on success, 0 otherwise
*/
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *node, *new_node;
	unsigned long int index;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node = find_node(ht, key, index);

	if (node != NULL)
	{
		free(node->value);
		node->value = strdup(value);
		return (1);
	}

	new_node = create_node(key, value);
	if (new_node == NULL)
		return (0);

	insert_node(ht, new_node, index);

	return (1);
}

/**
 * find_node - Find a node with the given key in the sorted hash table
 * @ht: hash table
 * @key: the key to search for
 * @index: index in the hash table
 *
 * Return: the node with the given key if found, or NULL if it fails
*/
shash_node_t *find_node(shash_table_t *ht,
		const char *key, unsigned long int index)
{
	shash_node_t *node = ht->array[index];
	int cmp;

	while (node != NULL)
	{
		cmp = strcmp(node->key, key);
		if (cmp == 0)
			return (node);
		else if (cmp > 0)
			break;
		node = node->next;
	}

	return (NULL);
}

/**
 * create_node - Create a new node with the given key and value
 * @key: key for the new node
 * @value: the new node
 *
 * Return: the newly created node, or NULL if it fails
*/
shash_node_t *create_node(const char *key, const char *value)
{
	shash_node_t *new_node = malloc(sizeof(shash_node_t));

	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = NULL;
	new_node->sprev = NULL;
	new_node->snext = NULL;

	return (new_node);
}

/**
 * insert_node - Insert a node into the hash table
 * @ht: hash table
 * @new_node:  node to insert
 * @index: The index in the hash table
 *
 * Return: nothing
*/
void insert_node(shash_table_t *ht,
		shash_node_t *new_node, unsigned long int index)
{
	shash_node_t *node = ht->array[index], *prev = NULL;

	while (node != NULL && strcmp(node->key, new_node->key) < 0)
	{
		prev = node;
		node = node->next;
	}
	if (prev == NULL)
		ht->array[index] = new_node;
	else
		prev->next = new_node;

	if (node != NULL)
		node->sprev = new_node;

	if (prev == NULL)
	{
		if (ht->shead == NULL)
		{
			ht->shead = new_node;
			ht->stail = new_node;
		}
		else
		{
			new_node->snext = ht->shead;
			ht->shead->sprev = new_node;
			ht->shead = new_node;
		}
	}
	else
	{
		new_node->sprev = prev;
		new_node->snext = prev->snext;
		if (prev->snext != NULL)
			prev->snext->sprev = new_node;
		else
			ht->stail = new_node;
		prev->snext = new_node;
	}
}

/**
 * shash_table_get - Retrieve the value associated with the given key
 * @ht: hash table
 * @key: the key to search for
 *
 * Return: the value, or NULL if it fails
*/
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	int cmp;
	unsigned long int index;

	if (ht == NULL || key == NULL)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node != NULL)
	{
		cmp = strcmp(node->key, key);
		if (cmp == 0)
			return (node->value);
		else if (cmp > 0)
			break;
		node = node->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Print the key-value pairs of the sorted hash table
 * @ht: hash table
 *
 * Return: nothing
*/
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	printf("{");
	node = ht->shead;
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		if (node->snext != NULL)
			printf(", ");
		node = node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Print the key-value pairs
 * @ht: hash table
 *
 * Return: nothing
*/
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	printf("{");
	node = ht->stail;
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		if (node->sprev != NULL)
			printf(", ");
		node = node->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Delete the hash table and free its memory
 * @ht: hash table
 *
 * Return: nothing
*/
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *next;
	unsigned long int i;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			next = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = next;

		}

		free(ht->array);
		free(ht);
	}
}
