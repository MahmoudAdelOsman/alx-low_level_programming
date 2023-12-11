#include <stdio.h>
#include <stdlib.h>
#include "../search_algos.h"

/**
 * print_skiplist - dump the content of a skiplist_t
 * @list: Pointer to the head of the list
 * Return: void
 */

void print_skiplist(const skiplist_t *list)
{
	const skiplist_t *x;

	printf("List :\n");
	for (x = list; x; x = x->next)
	{
		printf("Index[%lu] = [%d]\n", x->index, x->n);
	}
	printf("\nExpress lane :\n");
	for (x = list; x; x = x->express)
	{
		printf("Index[%lu] = [%d]\n", x->index, x->n);
	}
	printf("\n");
}
