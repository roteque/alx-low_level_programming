#include <stdio.h>
#include "variadic_functions.h"
#include <stdlib.h>

/**
 * main - A program to print numbers followeed by a new line.
 * @ separator: the string to be printed between two numbers.
 * @ n: the number of integers passed to the function.
 * NULL: if separator is NULL, don't print
 *
 */

void print_numbers(const char *separator, const unsigned int n, ...);
{
	const char *separator = ',';
	if(separator == NULL)
	{
		return 0;
	}
	int *c = (int*)  malloc(n * size_of(int));
	return (c);
}
