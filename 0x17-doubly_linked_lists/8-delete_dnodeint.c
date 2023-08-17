#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index index
 * @head: pointer to the first node
 * @index: the given position
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *a = *head;
	dlistint_t *b = *head;
	unsigned int x;
	unsigned int z = 0;

	if (!(*head))
		return (-1);
	if (index == 0)
	{
		*head = a->next;
		free(a);
		if (*head)
			(*head)->prev = NULL;
		return (1);
	}
	x = index - 1;
	while (b && z != x)
	{
		z++;
		b = b->next;
	}
	if (z == x && b)
	{
		a = b->next;
		if (a->next)
			a->next->prev = b;
		b->next = a->next;
		free(a);
		return (1);
	}
	return (-1);
}
