#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index index of
 * a listint_t linked list.
 * @head: Pointer to the first element in the list
 * @index: Index of the node to delete
 * Return: 1 Success, or -1 Fail
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *a = *head;
	listint_t *b = NULL;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(a);
		return (1);
	}

	for (i = 0; i < index - 1; i++)
	{
		if (!a || !(a->next))
			return (-1);
		a = a->next;
	}

	b = a->next;
	a->next = b->next;
	free(b);

	return (1);
}
