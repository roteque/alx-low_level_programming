#include <stdio.h>
#include <stdlib.h>
/**
 * Main - A program that prints the name of the file it was compile from
 * followed by a new line
 *
 */

int main()
{
	printf("%s\n", __FILE__);
	return 0;
}
