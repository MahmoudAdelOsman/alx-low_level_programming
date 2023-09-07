#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of new sorted hash table.
 * Return: If an error occurs - NULL.
 * Otherwise - a pointer to the new sorted hash table.
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *xx;
	unsigned long int z;

	xx = malloc(sizeof(shash_table_t));
	if (xx == NULL)
		return (NULL);

	xx->size = size;
	xx->array = malloc(sizeof(shash_node_t *) * size);
	if (xx->array == NULL)
		return (NULL);
	for (z = 0; z < size; z++)
		xx->array[z] = NULL;
	xx->shead = NULL;
	xx->stail = NULL;

	return (xx);
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 * Return: 0 on success Otherwise - 1.
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *xx, *xx1;
	char *a;
	unsigned long int z;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	a = strdup(value);
	if (a == NULL)
		return (0);

	z = key_index((const unsigned char *)key, ht->size);
	xx1 = ht->shead;
	while (xx1)
	{
		if (strcmp(xx1->key, key) == 0)
		{
			free(xx1->value);
			xx1->value = a;
			return (1);
		}
		xx1 = xx1->snext;
	}

	xx = malloc(sizeof(shash_node_t));
	if (xx == NULL)
	{
		free(a);
		return (0);
	}
	xx->key = strdup(key);
	if (xx->key == NULL)
	{
		free(a);
		free(xx);
		return (0);
	}
	xx->value = a;
	xx->next = ht->array[z];
	ht->array[z] = xx;

	if (ht->shead == NULL)
	{
		xx->sprev = NULL;
		xx->snext = NULL;
		ht->shead = xx;
		ht->stail = xx;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		xx->sprev = NULL;
		xx->snext = ht->shead;
		ht->shead->sprev = xx;
		ht->shead = xx;
	}
	else
	{
		xx1 = ht->shead;
		while (xx1->snext != NULL && strcmp(xx1->snext->key, key) < 0)
			xx1 = xx1->snext;
		xx->sprev = xx1;
		xx->snext = xx1->snext;
		if (xx1->snext == NULL)
			ht->stail = xx;
		else
			xx1->snext->sprev = xx;
		xx1->snext = xx;
	}

	return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key
 * in a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to get the value of.
 * Return: the value associated with the element,
 * or NULL if key couldn’t be found
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *xx;
	unsigned long int z;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	z = key_index((const unsigned char *)key, ht->size);
	if (z >= ht->size)
		return (NULL);

	xx = ht->shead;
	while (xx != NULL && strcmp(xx->key, key) != 0)
		xx = xx->snext;

	return ((xx == NULL) ? NULL : xx->value);
}

/**
 * shash_table_print - Prints a sorted hash table in order.
 * @ht: A pointer to the sorted hash table.
 * Return: nothing
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *xx;

	if (ht == NULL)
		return;

	xx = ht->shead;
	printf("{");
	while (xx != NULL)
	{
		printf("'%s': '%s'", xx->key, xx->value);
		xx = xx->snext;
		if (xx != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: A pointer to the sorted hash table to print.
 * Return: nothing
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *xx;

	if (ht == NULL)
		return;

	xx = ht->stail;
	printf("{");
	while (xx != NULL)
	{
		printf("'%s': '%s'", xx->key, xx->value);
		xx = xx->sprev;
		if (xx != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * Return: nothing
 */

void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *xx = ht;
	shash_node_t *xx1, *xx2;

	if (ht == NULL)
		return;

	xx1 = ht->shead;
	while (xx1)
	{
		xx2 = xx1->snext;
		free(xx1->key);
		free(xx1->value);
		free(xx1);
		xx1 = xx2;
	}

	free(xx->array);
	free(xx);
}
