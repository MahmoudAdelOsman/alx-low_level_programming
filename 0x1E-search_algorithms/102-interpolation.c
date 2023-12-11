#include "search_algos.h"

/**
  * interpolation_search - Searches for a value in a sorted array
  *                        of integers using interpolation search.
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  * Return: If the value is not present or the array is NULL, -1.
  *         Otherwise, the first index where the value is located.
  */

int interpolation_search(int *array, size_t size, int value)
{
	size_t z, x1, x2;

	if (array == NULL)
		return (-1);
	for (x1 = 0, x2 = size - 1; x2 >= x1;)
	{
		z = x1 + (((double)(x2 - x1) / (array[x2] - array[x1])) *
				(value - array[x1]));
		if (z < size)
			printf("Value checked array[%ld] = [%d]\n", z, array[z]);
		else
		{
			printf("Value checked array[%ld] is out of range\n", z);
			break;
		}
		if (array[z] == value)
			return (z);
		if (array[z] > value)
			x2 = z - 1;
		else
			x1 = z + 1;
	}
	return (-1);
}
