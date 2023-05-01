#include "lists.h"

/**
  * reverse_listint - reverses linked list
  * @h: Pointer to the first node in the list
  * Return: Pointer to first node in new list
  */
listint_t *reverse_listint(listint_t **h)
{
	listint_t *prv = NULL;
	listint_t *next = NULL;

	while (*h)
	{
		next = (*h)->next;
		(*h)->next = prv;
		prv = *h;
		*h = next;
	}

	*h = prv;

	return (*h);
}
