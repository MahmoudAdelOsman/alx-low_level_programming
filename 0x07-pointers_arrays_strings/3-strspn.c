#include "main.h"

/**
 * _strspn - Returns the number of bytes in the initial segment of s
 * @s: the first input string
 * @accept: the second input string
 * Return: Returns the number of bytes in the initial segment of s (n)
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int n = 0;
	int i;

	while (*s)
	{
		for (i = 0 ; accept[i] ; i++)
		{
			if (*s == accept[i])
			{
				n++;
				break;
			}
			else if (accept[i + 1] == '\0')
				return (n);
		}
		s++;
	}
	return (n);
}
