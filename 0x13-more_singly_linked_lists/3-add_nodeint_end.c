#include "lists.h"

/**
 * add_nodeint_end - adds a node at the end of a linked list
 * @head: pointer to the first element in the list
 * @n: data to insert in the new element
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *a;
	listint_t *b = *head;

	a = malloc(sizeof(listint_t));
	if (!a)
		return (NULL);

	a->n = n;
	a->next = NULL;

	if (*head == NULL)
	{
		*head = a;
		return (a);
	}

	while (b->next)
		b = b->next;

	b->next = a;

	return (a);
}
