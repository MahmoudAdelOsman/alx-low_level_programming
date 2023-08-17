#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data (n)
 * of a dlistint_t linked list
 * @head: pointer to the first node
 * Return: sum of all the data, if the list is empty, return 0
 */

int sum_dlistint(dlistint_t *head)
{
	dlistint_t *x = head;
	int a = 0;

	while (x)
	{
		a += x->n;
		x = x->next;
	}
	return (a);
}
