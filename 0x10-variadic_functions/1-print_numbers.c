#include <stdio.h>
#include "variadic_functions.h"
#include <stdarg.h>

/**
 * main - A program to print numbers followeed by a new line.
 * @ separator: the string to be printed between two numbers.
 * @ n: the number of integers passed to the function.
 * NULL: if separator is NULL, don't print
 *
 * Return Always 0 (Success)
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{	
	va_list print;
		unsigned int i;

		va_start(print, n);
		for (i = 0; i < n; i++)
		{
			printf("%d\n", va_arg(print, int));
			if (i != (n-1) && separator != NULL)
				printf("%s", separator);
		}
		printf("\n");
		va_end(print);
}
