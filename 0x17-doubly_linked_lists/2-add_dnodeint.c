#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 * @head: pointer to the first node
 * @n: the node first node inserted
 * Return: the address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *x;

	x = malloc(sizeof(dlistint_t));
	if (x == NULL)
		return (NULL);
	x->n = n;
	x->prev = NULL;
	x->next = *head;
	if (*head)
		(*head)->prev = x;
	*head = x;
	return (x);
}
