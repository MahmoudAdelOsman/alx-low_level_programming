#include "main.h"

/**
 * _strlen_recursion - needed function to return the length of a string
 * @s: needed string input to be measured
 *Return: the needed output (the length of string)
 */

int _strlen_recursion(char *s)
{
	int x = 0;

	if (*s)
	{
		x++;
		x += _strlen_recursion(s + 1);
	}
	return (x);
}
