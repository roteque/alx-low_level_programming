#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * binary_to_uint -  converts binary numbers to an unsigned int
 * @b: numbers to convert
 *
 * Return: the pointer to a string of 0 and 1 characters
 */

unsigned int binary_to_uint(const char *b)

{
	unsigned int decimal_value = 0;

	if (b == NULL)
{
	return (0);
	}

	while (*b != '\0')
	{
	if (*b == '0' || *b == '1')
	{

	decimal_value = (decimal_value << 1) | (*b - '0');
	}
	else
	{
	return (0);
	}
	b++;
	}

	return (decimal_value);
}
