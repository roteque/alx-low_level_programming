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
	int d;

	for (d = '0'; d <= '9'; d++)
	{
	putchar(d);
	if (d != '9')
	{
	putchar(',');
	putchar(' ');
	}
	}
	putchar ('\n');
return (0);
}
