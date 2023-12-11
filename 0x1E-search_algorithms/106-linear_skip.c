#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted singly linked list
 *               of integers using linear skip.
 * @list: A pointer to the head of the linked list to search.
 * @value: The value to search for.
 * Return: If the value is not present or the head of the list is NULL, NULL.
 *         Otherwise, a pointer to the first node where the value is located.
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *x, *xx;

	if (list == NULL)
		return (NULL);
	for (x = xx = list; xx->next != NULL && xx->n < value;)
	{
		x = xx;
		if (xx->express != NULL)
		{
			xx = xx->express;
			printf("Value checked at index [%ld] = [%d]\n", xx->index, xx->n);
		}
		else
		{
			while (xx->next != NULL)
				xx = xx->next;
		}
	}
	printf("Value found between indexes [%ld] and [%ld]\n",
			x->index, xx->index);
	for (; x->index < xx->index && x->n < value; x = x->next)
		printf("Value checked at index [%ld] = [%d]\n", x->index, x->n);
	printf("Value checked at index [%ld] = [%d]\n", x->index, x->n);
	return (x->n == value ? x : NULL);
}
