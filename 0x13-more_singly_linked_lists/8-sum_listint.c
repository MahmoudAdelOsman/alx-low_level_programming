#include "lists.h"

/**
 * sum_listint - calculates the sum of all the data in a listint_t list
 * @head: First node in the linked list
 * Return: Summition
 */

int sum_listint(listint_t *head)
{
	int x = 0;
	listint_t *y = head;

	while (y)
	{
		x += y->n;
		y = y->next;
	}

	return (x);
}
