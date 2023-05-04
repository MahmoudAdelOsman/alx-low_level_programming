#include "main.h"

/**
  * flip_bits - returns the number of bits you would need to
  * flip to get from one number to another
  * @n: First number
  * @m: Second number
  * Return: number of bits to change
  */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int x, y = 0;
	unsigned long int z;
	unsigned long int o = n ^ m;

	for (x = 63; x >= 0; x--)
	{
		z = o >> x;
		if (z & 1)
			y++;
	}

	return (y);
}
