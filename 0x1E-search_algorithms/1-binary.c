#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array
 *                 of integers using binary search.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index where the value is located.
 */

int binary_search(int *array, size_t size, int value)
{
	size_t z, x1, x2;

	if (array == NULL)
		return (-1);
	for (x1 = 0, x2 = size - 1; x2 >= x1;)
	{
		printf("Searching in array: ");
		for (z = x1; z < x2; z++)
			printf("%d, ", array[z]);
		printf("%d\n", array[z]);
		z = x1 + (x2 - x1) / 2;
		if (array[z] == value)
			return (z);
		if (array[z] > value)
			x2 = z - 1;
		else
			x1 = z + 1;
	}
	return (-1);
}
