#include "lists.h"

/**
  * free_listint_safe - frees a linked list
  * @h: Pointer to the first node in the linked list
  * Return: Number of elements in the freed list
  */
size_t free_listint_safe(listint_t **h)
{
	size_t s = 0;
	int d;
	listint_t *t;

	if (!h || !*h)
		return (0);

	for (s = 0; *h; s++)
	{
		d = *h - (*h)->next;
		if (d > 0)
		{
			t = (*h)->next;
			free(*h);
			*h = t;
			s++;
		}
		else
		{
			free(*h);
			*h = NULL;
			s++;
			break;
		}
	}

	*h = NULL;
	return (s);
}
