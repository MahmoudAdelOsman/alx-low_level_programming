#include "main.h"

/**
 * _strpbrk - function needed
 * @s: first input
 * @accept: second input
 * Return: output
 */

char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s)
	{
		for (i = 0 ; accept[i] ; i++)
		{
			if (*s == accept[i])
				return (s);
		}
		s++;
	}
	return ('\0');
}
