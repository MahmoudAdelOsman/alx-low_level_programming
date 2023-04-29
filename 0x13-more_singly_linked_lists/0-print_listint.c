#include "lists.h"

/**
 * print_listint - prints all the elements of a linked list
 * @h: Linked list of type listint_t to print
 * Return: Number of nods
 */
size_t print_listint(const listint_t *h)
{
	size_t nods = 0;

	while (h)
	{
		nods++;
		printf("%d\n", h->n);
		h = h->next;
	}

	return (nods);
}
