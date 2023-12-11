#include <stdlib.h>
#include "../search_algos.h"

/**
 * free_skiplist - Deallocates a singly linked list
 * @list: Pointer to the linked list to be freed
 */

void free_skiplist(skiplist_t *list)
{
	skiplist_t *x;

	if (list)
	{
		x = list->next;
		free(list);
		free_skiplist(x);
	}
}
