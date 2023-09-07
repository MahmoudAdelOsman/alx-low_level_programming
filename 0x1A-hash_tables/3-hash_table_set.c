#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to add.
 * @value: The value associated with key.
 * Return: 1 if it succeeded, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *xx;
	char *a;
	unsigned long int n, z;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	a = strdup(value);
	if (a == NULL)
		return (0);

	n = key_index((const unsigned char *)key, ht->size);
	for (z = n; ht->array[z]; z++)
	{
		if (strcmp(ht->array[z]->key, key) == 0)
		{
			free(ht->array[z]->value);
			ht->array[z]->value = a;
			return (1);
		}
	}

	xx = malloc(sizeof(hash_node_t));
	if (xx == NULL)
	{
		free(a);
		return (0);
	}
	xx->key = strdup(key);
	if (xx->key == NULL)
	{
		free(xx);
		return (0);
	}
	xx->value = a;
	xx->next = ht->array[n];
	ht->array[n] = xx;

	return (1);
}
