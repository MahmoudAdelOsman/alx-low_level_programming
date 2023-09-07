#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to a hash table.
 * Return: nothing
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *xx = ht;
	hash_node_t *xx1, *xx2;
	unsigned long int z;

	for (z = 0; z < ht->size; z++)
	{
		if (ht->array[z] != NULL)
		{
			xx1 = ht->array[z];
			while (xx1 != NULL)
			{
				xx2 = xx1->next;
				free(xx1->key);
				free(xx1->value);
				free(xx1);
				xx1 = xx2;
			}
		}
	}
	free(xx->array);
	free(xx);
}
