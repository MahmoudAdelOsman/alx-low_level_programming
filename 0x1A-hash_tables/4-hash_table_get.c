#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: a pointer to the hash table.
 * @key: the key you are looking for
 * Return: the value associated with the element,
 * or NULL if key couldn’t be found
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *xx;
	unsigned long int z;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	z = key_index((const unsigned char *)key, ht->size);
	if (z >= ht->size)
		return (NULL);

	xx = ht->array[z];
	while (xx && strcmp(xx->key, key) != 0)
		xx = xx->next;

	return ((xx == NULL) ? NULL : xx->value);
}
