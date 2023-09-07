#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table.
 * @size: size of the array.
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *xx;
	unsigned long int z;

	xx = malloc(sizeof(hash_table_t));
	if (xx == NULL)
		return (NULL);

	xx->size = size;
	xx->array = malloc(sizeof(hash_node_t *) * size);
	if (xx->array == NULL)
		return (NULL);
	for (z = 0; z < size; z++)
		xx->array[z] = NULL;

	return (xx);
}
