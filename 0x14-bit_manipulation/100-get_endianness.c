#include "main.h"

/**
  * get_endianness - checks the endianness
  * Return: 0 for big, 1 for little
  */

int get_endianness(void)
{
	unsigned int a = 1;
	char *b = (char *) &a;

	return (*b);
}
