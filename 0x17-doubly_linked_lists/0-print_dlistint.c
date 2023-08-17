#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 * @h: pointer to the first node
 * Return: the number of nodes
 */

size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *x = h;
	size_t i = 0;

	while (x)
	{
		printf("%i\n", x->n);
		i++;
		x = x->next;
	}
	return (i);
}
