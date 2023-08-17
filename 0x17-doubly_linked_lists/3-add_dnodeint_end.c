#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: pointer to the first node
 * @n: the new node inserted
 * Return: the address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *a;
	dlistint_t *b = *head;

	a = malloc(sizeof(dlistint_t));
	if (a == NULL)
		return (NULL);
	a->n = n;
	a->next = NULL;
	if (b)
	{
		while (b->next)
			b = b->next;
		a->prev = b;
		b->next = a;
	}
	else
	{
		*head = a;
		a->prev = NULL;
	}
	return (a);
}
