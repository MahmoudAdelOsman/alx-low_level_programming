#include "lists.h"
/**
 * free_listint2 - frees a linked list
 * @head: Pointer to the listint_t list to be free
 */
void free_listint2(listint_t **head)
{
	listint_t *f;

	if (head == NULL)
		return;

	while (*head)
	{
		f = (*head)->next;
		free(*head);
		*head = f;
	}

	*head = NULL;
}
