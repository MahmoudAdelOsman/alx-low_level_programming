#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * check_number - checks a string is a number
 * @s: needed string
 * Return: 0 (Success) , 1 (Error)
 */

int check_number(char *s)
{
	unsigned int i;

	for (i = 0 ; i < strlen(s) ; i++)
	{
		if (!isdigit(s[i]))
			return (0);
	}
	return (1);
}

/**
 * main - adds positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: always 0 (success)
 */

int main(int argc, char *argv[])
{
	int i;
	int sum = 0;

	for (i = 1 ; i < argc ; i++)
	{
		if (check_number(argv[i]))
			sum += atoi(argv[i]);
		else
		{
			printf("Error\n");
			return (1);
		}
	}
	printf("%d\n", sum);
	return (0);
}
