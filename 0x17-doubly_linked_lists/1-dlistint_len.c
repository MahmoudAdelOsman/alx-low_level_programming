#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a linked dlistint_t list
 * @h: pointer to the first node
 * Return: number of elements
 */

size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *x = h;
	size_t i = 0;

	while (x)
	{
		i++;
		x = x->next;
	}
	return (i);
}
