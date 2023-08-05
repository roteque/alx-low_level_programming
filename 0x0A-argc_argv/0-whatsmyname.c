#include <stdio.h>
#include <stdlib.h>
/**
 * main - this program writes the name of itself
 * @./mynameis ./mynameis
 * Return: 0 (Success)
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);

	return (0);
}
