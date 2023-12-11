#include "search_algos.h"

/**
 * advanced_binary_recursive - Searches recursively for a value in a sorted
 *                             array of integers using binary search.
 * @array: A pointer to the first element of the [sub]array to search.
 * @x1: The starting index of the [sub]array to search.
 * @x2: The ending index of the [sub]array to search.
 * @value: The value to search for.
 * Return: If the value is not present, -1.
 *         Otherwise, the index where the value is located.
 */

int advanced_binary_recursive(int *array, size_t x1, size_t x2, int value)
{
	size_t z;

	if (x2 < x1)
		return (-1);
	printf("Searching in array: ");
	for (z = x1; z < x2; z++)
		printf("%d, ", array[z]);
	printf("%d\n", array[z]);
	z = x1 + (x2 - x1) / 2;
	if (array[z] == value && (z == x1 || array[z - 1] != value))
		return (z);
	if (array[z] >= value)
		return (advanced_binary_recursive(array, x1, z, value));
	return (advanced_binary_recursive(array, z + 1, x2, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array
 *                   of integers using advanced binary search.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the first index where the value is located.
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);
	return (advanced_binary_recursive(array, 0, size - 1, value));
}
