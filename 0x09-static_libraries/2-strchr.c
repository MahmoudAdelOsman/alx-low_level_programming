#include "main.h"

/**
 * _strchr - function that returns a pointer to the first occurrence of c in s
 * @s: the string that we will search inside it
 * @c: the character that we will search on it
 * Return: a pointer to c in s or NULL if the character is not found
 */

char *_strchr(char *s, char c)
{
	int i;

	for (i = 0 ; s[i] >= '\0' ; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (0);
}
