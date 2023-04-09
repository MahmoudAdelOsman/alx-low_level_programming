#include "main.h"

/**
 * _strstr - function needed
 * @haystack: first input
 * @needle: second input
 * Return: needed output
 */

char *_strstr(char *haystack, char *needle)
{
	for ( ; *haystack != '\0' ; haystack++)
	{
		char *i = haystack;
		char *n = needle;

		while (*i == *n && *n != '\0')
		{
			i++;
			n++;
		}
		if (*n == '\0')
			return (haystack);
	}
	return (0);
}
