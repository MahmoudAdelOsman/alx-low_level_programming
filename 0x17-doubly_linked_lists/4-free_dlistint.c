#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list
 * @head: pointer to the first node
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *a, *b;

	if (head)
	{
		a = head;
		b = head->next;
		while (b)
		{
			free(a);
			a = b;
			b = b->next;
		}
		free(a);
	}
}
