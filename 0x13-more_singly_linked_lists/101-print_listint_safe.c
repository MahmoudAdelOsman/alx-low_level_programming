#include "lists.h"

/**
 * list_len - counts unique nodes
 * @head: pointer to the first node
 * Return: number of unique nodes
 */

size_t list_len(const listint_t *head)
{
	const listint_t *a, *b;
	size_t c = 1;

	if (head == NULL || head->next == NULL)
		return (0);
	a = head->next;
	b = (head->next)->next;
	while (b)
	{
		if (a == b)
		{
			a = head;
			for (; a != b; c++)
			{
				a = a->next;
				b = b->next;
			}
			a = a->next;
			for (; a != b; c++)
				a = a->next;
			return (c);
		}
		a = a->next;
		b = (b->next)->next;
	}
	return (0);
}

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the first node
 * Return: number of nodes
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t x, i = 0;

	x = list_len(head);
	if (x == 0)
	{
		for (; head != NULL; x++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (; i < x; i++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (x);
}
