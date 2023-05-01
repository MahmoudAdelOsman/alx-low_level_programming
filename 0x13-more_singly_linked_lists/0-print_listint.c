#include "lists.h"

/**
 * print_listint - prints all elements of the linked list
 * @x: linked list of type listint_t
 * Return: number of nodes
 */
size_t print_listint(const listint_t *x)
{
	size_t nm = 0;

	while (x)
	{
		printf("%d\n", x->n);
		nm++;
		x = x->next;
	}
	return (nm);
}
