#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: pointer to the first node
 * @index: nth node
 * Return: the index of the node, starting from 0,
 * if the node does not exist, return NULL
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *x = head;
	unsigned int z = 0;

	while (x && z != index)
	{
		z++;
		x = x->next;
	}
	if (x && z == index)
		return (x);
	return (NULL);
}
