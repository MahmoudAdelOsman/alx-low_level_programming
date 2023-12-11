#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted singly linked list
 *             of integers using jump search.
 * @list: A pointer to the head of the linked list to search.
 * @size: The number of nodes in the list.
 * @value: The value to search for.
 * Return: If the value is not present or the head of the list is NULL, NULL.
 *         Otherwise, a pointer to the first node where the value is located.
 */

listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t a, l_a;
	listint_t *x, *xx;

	if (list == NULL || size == 0)
		return (NULL);
	a = 0;
	l_a = sqrt(size);
	for (x = xx = list; xx->index + 1 < size && xx->n < value;)
	{
		x = xx;
		for (a += l_a; xx->index < a; xx = xx->next)
		{
			if (xx->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", xx->index, xx->n);
	}
	printf("Value found between indexes [%ld] and [%ld]\n",
			x->index, xx->index);
	for (; x->index < xx->index && x->n < value; x = x->next)
		printf("Value checked at index [%ld] = [%d]\n", x->index, x->n);
	printf("Value checked at index [%ld] = [%d]\n", x->index, x->n);
	return (x->n == value ? x : NULL);
}
