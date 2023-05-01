#include "lists.h"

/**
  * reverse_listint - reverses linked list
  * @h: Pointer to the first node in the list
  * Return: Pointer to first node in new list
  */
listint_t *reverse_listint(listint_t **h)
{
	listint_t *prv = NULL;
	listint_t *nxt = NULL;

	while (*h)
	{
		nxt = (*h)->nxt;
		(*h)->nxt = prv;
		prv = *h;
		*h = nxt;
	}

	*h = prv;

	return (*h);
}
