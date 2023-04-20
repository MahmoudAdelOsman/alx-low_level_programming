#include "3-calc.h"

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/**
 * op_add - sum of two numbers
 * @a: the first number
 * @b: the second number
 * Return: sum of a and b
 */

int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - difference of two numbers
 * @a: the first number
 * @b: the second number
 * Return: difference of a and b
 */

int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - product of two numbers
 * @a: the first number
 * @b: the second number
 * Return: product of a and b
 */

int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - division of two numbers
 * @a: the first number
 * @b: the second number
 * Return: division of a and b
 */

int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - remainder of two numbers
 * @a: the first number
 * @b: the second number
 * Return: remainder of a and b
 */

int op_mod(int a, int b)
{
	return (a % b);
}
