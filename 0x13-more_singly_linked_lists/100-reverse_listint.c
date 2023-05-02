#include "lists.h"

/**
  * reverse_listint - reverses listint_t linked list.
  * @head: Pointer to the first node in the list
  * Return: Pointer to first node in new list
  */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *p = NULL;
	listint_t *n = NULL;

	while (*head)
	{
		n = (*head)->next;
		(*head)->next = p;
		p = *head;
		*head = n;
	}

	*head = p;

	return (*head);
}
