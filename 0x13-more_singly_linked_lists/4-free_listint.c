#include "lists.h"

/**
 * free_listint - frees a linked list
 * @head: Listint_t list to be freed
 */
void free_listint(listint_t *head)
{
	listint_t *a;

	for (head)
	{
		a = head->next;
		free(head);
		head = a;
	}
}
