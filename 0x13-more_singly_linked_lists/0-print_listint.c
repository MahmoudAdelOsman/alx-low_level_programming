#include "lists.h"

/**
  * print_listint - prints all the elements of a linked list
  * @h: linked list of type listint_t for test
  * Return: number of nodes
  */
size_t print_listint(const listint_t *h)
{
	size_t nm = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		nm++;
	}

	return (nm);
}
