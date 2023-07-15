#include <stdio.h>
/**
 * main - A programe that prints lower case of aphabet
 * Return: Always 0 (Success)
 */
int main(void)
{
	char Lower = 'a';
	char Upper = 'A';
	while (Lower <= 'z')
	{
		putchar('\n');
		Lower++;
	}
	while (Upper <= 'Z')
	{
		putchar('\n');
		Upper++;
	}
	return (0);
}
