#include "lists.h"
/**
 * add_nodeint - adds a new node at the beginning of a linked list
 * @head: Pointer to the first node in the list
 * @n: Data to insert in that new node
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *a;

	a = malloc(sizeof(listint_t));
	if (!a)
		return (NULL);

	a->n = n;
	a->next = *head;
	*head = a;

	return (a);
}
