#include <stdlib.h>
#include "../search_algos.h"

void free_list(listint_t *list);

/**
 * create_list - Creates a single linked list
 * @array: Pointer to the array to use to fill the list
 * @size: Size of the array
 * Return: A pointer to the head of the created list (NULL on failure)
 */

listint_t *create_list(int *array, size_t size)
{
	listint_t *list;
	listint_t *x;

	list = NULL;
	while (array && size--)
	{
		x = malloc(sizeof(*x));
		if (!x)
		{
			free_list(list);
			return (NULL);
		}
		x->n = array[size];
		x->index = size;
		x->next = list;
		list = x;
	}
	return (list);
}
