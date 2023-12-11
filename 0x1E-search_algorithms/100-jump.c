#include "search_algos.h"

/**
  * jump_search - Searches for a value in a sorted array
  *               of integers using jump search.
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  * Return: If the value is not present or the array is NULL, -1.
  *         Otherwise, the first index where the value is located.
  */

int jump_search(int *array, size_t size, int value)
{
	size_t z, a, x;

	if (array == NULL || size == 0)
		return (-1);
	x = sqrt(size);
	for (z = a = 0; a < size && array[a] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", a, array[a]);
		z = a;
		a += x;
	}
	printf("Value found between indexes [%ld] and [%ld]\n", z, a);
	a = a < size - 1 ? a : size - 1;
	for (; z < a && array[z] < value; z++)
		printf("Value checked array[%ld] = [%d]\n", z, array[z]);
	printf("Value checked array[%ld] = [%d]\n", z, array[z]);
	return (array[z] == value ? (int)z : -1);
}
