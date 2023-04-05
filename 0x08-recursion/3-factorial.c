#include "main.h"

/**
 * factorial - needed function that returns the factorial of a number
 * @n: needed number to return the factorial from
 * Return: the factorial of n
 */

int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (1);
	else
		return (n * factorial(n - 1));
}
