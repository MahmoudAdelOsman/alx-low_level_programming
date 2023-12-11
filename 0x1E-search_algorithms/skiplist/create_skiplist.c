#include <stdlib.h>
#include <math.h>
#include "../search_algos.h"

void free_skiplist(skiplist_t *list);

/**
 * init_express - Initializes the express lane of the linked list
 * @list: Pointer to the head node of the list
 * @size: Number of nodes in the list
 */

void init_express(skiplist_t *list, size_t size)
{
	const size_t a = sqrt(size);
	size_t z;
	skiplist_t *x;

	for (x = list, z = 0; z < size; ++z, list = list->next)
	{
		if (z % a == 0)
		{
			x->express = list;
			x = list;
		}
	}
}

/**
 * create_skiplist - Create a single linked list
 * @array: Pointer to the array used to fill the list
 * @size: Size of the array
 * Return: A pointer to the head of the created list (NULL on failure)
 */

skiplist_t *create_skiplist(int *array, size_t size)
{
	skiplist_t *list;
	skiplist_t *x;
	size_t q;

	list = NULL;
	q = size;
	while (array && size--)
	{
		x = malloc(sizeof(*x));
		if (!x)
		{
			free_skiplist(list);
			return (NULL);
		}
		x->n = array[size];
		x->index = size;
		x->express = NULL;
		x->next = list;
		list = x;
	}
	init_express(list, q);
	return (list);
}
