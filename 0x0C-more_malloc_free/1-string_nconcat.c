#include <stdlib.h>
#include "main.h"

/**
 * *string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes from s2 to concatenate
 * Return: pointer to full string
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *s;
	unsigned int i, j, len1 = 0, len2 = 0;

	while (s1 && s1[len1])
		len1++;
	while (s2 && s2[len2])
		len2++;
	if (n < len2)
		s = malloc(sizeof(char) * (len1 + n + 1));
	else
		s = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!s)
		return (NULL);
	for (i = 0 ; i < len1 ; i++)
		s[i] = s1[i];
	for (j = 0 ; n < len2 && i < (len1 + n) ; j++)
		s[i++] = s2[j];
	for (j = 0 ; n >= len2 && i < (len1 + len2) ; j++)
		s[i++] = s2[j];
	s[i] = '\0';
	return (s);
}
