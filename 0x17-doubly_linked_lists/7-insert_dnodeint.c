#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to the first node
 * @idx: the given position
 * @n: the new node inserted
 * Return: the address of the new node, or NULL if it failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *a, *b = *h;
	unsigned int z = 0, x;

	a = malloc(sizeof(dlistint_t));
	if (a == NULL)
		return (NULL);
	a->n = n;
	if (idx == 0)
	{
		a->prev = NULL;
		a->next = *h;
		if (*h)
			(*h)->prev = a;
		*h = a;
		return (*h);
	}
	x = idx - 1;
	while (b && z != x)
	{
		z++;
		b = b->next;
	}
	if (z == x && b)
	{
		a->prev = b;
		a->next = b->next;
		if (b->next)
			b->next->prev = a;
		b->next = a;
		return (a);
	}
	free(a);
	return (NULL);
}
