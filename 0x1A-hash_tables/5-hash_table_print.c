#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table.
 * @ht: A pointer to the hash table.
 * Return: nothing
 */

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *xx;
	unsigned long int z;
	unsigned char a = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (z = 0; z < ht->size; z++)
	{
		if (ht->array[z] != NULL)
		{
			if (a == 1)
				printf(", ");

			xx = ht->array[z];
			while (xx != NULL)
			{
				printf("'%s': '%s'", xx->key, xx->value);
				xx = xx->next;
				if (xx != NULL)
					printf(", ");
			}
			a = 1;
		}
	}
	printf("}\n");
}
