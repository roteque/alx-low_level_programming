#include <stdio.h>
#include <stdlib.h>
/**
 * main - A program that prints all lower case alphabet except q and e
 * Return: Always 0 (Succes)
 */
int main(void)
{
	char i;

	for (i = 'z'; i >= 'a'; i--)
	putchar(i);

	putchar('\n');
return (0);
}
