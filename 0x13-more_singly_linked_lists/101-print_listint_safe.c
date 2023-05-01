#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
  * looped_listint_len - counts the number of uniqe nodes
  * in a looped listint_t linked list
  * @head: A pointer to the head for check
  * Return: If the list is not looped 0
  */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *test, *x;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	test = head->next;
	x = (head->next)->next;

	while (x)
	{
		if (test == x)
		{
			test = head;
			while (test != x)
			{
				nodes++;
				test = test->next;
				x = x->next;
			}

			test = test->next;
			while (test != x)
			{
				nodes++;
				test = test->next;
			}

			return (nodes);
		}

		test = test->next;
		x = (x->next)->next;
	}
	return (0);
}

/**
  * print_lsitint_safe - prints a lsitint_t list safely
  * @head: A pointer to the head of the listint_t list
  * Return: The number of nodes in the list
  */
size_t print_listint_safe(const listint_t *head)
{
	size_t x, y = 0;

	x = looped_listint_len(head);

	if (x == 0)
	{
		for (; head != NULL; x++)
		{
			printf("[%p]%d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (y = 0; y < x; y++)
		{
			printf("[%p]%d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("->[%p]%d\n", (void *)head, head->n);
	}

	return (x);
}
