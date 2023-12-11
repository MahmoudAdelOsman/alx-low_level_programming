#include "search_algos.h"

/**
  * _binary_search - Searches for a value in a sorted array
  *                  of integers using binary search.
  * @array: A pointer to the first element of the array to search.
  * @left: The starting index of the [sub]array to search.
  * @x: The ending index of the [sub]array to search.
  * @value: The value to search for.
  * Return: If the value is not present or the array is NULL, -1.
  *         Otherwise, the index where the value is located.
  */

int _binary_search(int *array, size_t left, size_t x, int value)
{
	size_t z;

	if (array == NULL)
		return (-1);
	while (x >= left)
	{
		printf("Searching in array: ");
		for (z = left; z < x; z++)
			printf("%d, ", array[z]);
		printf("%d\n", array[z]);
		z = left + (x - left) / 2;
		if (array[z] == value)
			return (z);
		if (array[z] > value)
			x = z - 1;
		else
			left = z + 1;
	}
	return (-1);
}

/**
  * exponential_search - Searches for a value in a sorted array
  *                      of integers using exponential search.
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  * Return: If the value is not present or the array is NULL, -1.
  *         Otherwise, the index where the value is located.
  */

int exponential_search(int *array, size_t size, int value)
{
	size_t z = 0, x;

	if (array == NULL)
		return (-1);
	if (array[0] != value)
	{
		for (z = 1; z < size && array[z] <= value; z = z * 2)
			printf("Value checked array[%ld] = [%d]\n", z, array[z]);
	}
	x = z < size ? z : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", z / 2, x);
	return (_binary_search(array, z / 2, x, value));
}
