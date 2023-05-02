#include "lists.h"

/**
 * get_nodeint_at_index - returns the node at a certain index in a linked list
 * @head: First node in the linked list
 * @index: Index of the node to return
 * Return: Pointer to the node we're looking for, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *u = head;

	for (i = 0; u && i < index; i++)
		u = u->next;
	if (u)
		return (u);
	else
		return (NULL);
}
