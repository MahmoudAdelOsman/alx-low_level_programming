#include "main.h"

/**
 *  _pow_recursion - Returns the value of x raised to the power of y
 * @x: The value to multiplay
 * @y: The times to multiplay the value
 * Return: The value multiplied y times
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);

	if (y == 0)
		return (1);

	return (x * _pow_recursion(x, y - 1));
}
