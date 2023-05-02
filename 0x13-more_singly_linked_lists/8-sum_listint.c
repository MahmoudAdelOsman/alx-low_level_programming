#include "lists.h"

/**
 * sum_listint - calculates the sum of all the data in a listint_t list
 * @head: First node in the linked list
 * Return: Summition
 */
int sum_listint(listint_t *head)
{
	int s = 0;
	listint_t *x = head;

	while (x)
	{
		s += x->n;
		x = x->next;
	}

	return (s);
}
