#include "function_pointer.h"
#include <stdio>

/**
  * print_name - prints a name
  * @name: nedded string input
  * @f: printer to function
  * Return: nothing
  */

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}
