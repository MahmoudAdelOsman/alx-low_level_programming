#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - needed function
 * @a: needed first input
 * @size: needed second input
 * Return: needed output
 */

void print_diagsums(int *a, int size)
{
	int s1 = 0;
	int s2 = 0;
	int i;

	for (i = 0 ; i < size ; i++)
		s1 += a[i * size + i];
	for (i = size - 1 ; i >= 0 ; i--)
		s2 += a[i * size + size - i - 1];
	printf("%d, %d\n", s1, s2);
}
