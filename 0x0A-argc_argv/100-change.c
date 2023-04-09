#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the minimum number of coins
 * to make change for an amount of money
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 (Success) , 1 (Error)
 */

int main(int argc, char *argv[])
{
	int i, x;
	int result = 0;
	int coins[] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	x = atoi(argv[1]);
	for (i = 0 ; i < 5 && x >= 0 ; i++)
	{
		while (x >= coins[i])
		{
			result++;
			x -= coins[i];
		}
	}
	printf("%d\n", result);
	return (0);
}
