#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
/**
 * main - A program that prints all lower case alphabet except q and e
 * Return: Always 0 (Succes)
 */
int main(void)
{
	int c;
	char low;

	for (c = '0'; c <= '9'; c++)
	putchar(c);
	for (low = 'a'; low <= 'f'; low++)
	putchar(low);
	putchar('\n');
return (0);
}
