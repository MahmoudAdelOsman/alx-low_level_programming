#include "lists.h"

/**
  * print_listint - Prints all the elements of a linked list
  * @x: Linked list of type listint_t to print
  * Return: Number of nodes
  */
size_t print_listint (const listint_t *x)
{
	size_t num = 0;

	while (x)
	{
		printf("%d\n", x->n);
		num++;
		x = x->next;
	}

	return (num);
}
/*prints all the elements of a listint_t list.*/
