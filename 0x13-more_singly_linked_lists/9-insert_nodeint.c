#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node in a linked list
 * at a given position
 * @head: Pointer to the first node in the list
 * @idx: Index where the new node is added
 * @n: Data to insert in the new node
 * Return: Pointer to the new node
 * or NULL
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new_ele;
	listint_t *m = *head;

	new_ele = malloc(sizeof(listint_t));
	if (!new_ele || !head)
	return (NULL);

	new_ele->n = n;
	new_ele->next = NULL;

	if (idx == 0)
	{
		new_ele->next = *head;
		*head = new_ele;
		return (new_ele);
	}

	for (i = 0; m && i < idx; i++)
	{
		if (i == idx - 1)
		{

			new_ele->next = m->next;
			m->next = new_ele;
			return (new_ele);
		}

		else
			m = m->next;
	}

	return (NULL);
}
