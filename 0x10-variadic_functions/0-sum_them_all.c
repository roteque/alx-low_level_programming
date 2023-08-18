#include <stdio.h>
#include "variadic_functions.h"
#include <stdarg.h>

/**
 * main - A program to add n numbers of numbers
 * @n: number of arguments
 * check if n == 0 and returns 0
 *
 * Return the sum
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list list;
	unsigned int i, sum = 0;

	va_start(list, n);

	for (i = 0; i < n; i++)
	{
		sum += va_arg(list, int);
	}
	va_end(list);
	return (sum);
}
