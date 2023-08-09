#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * _strdup - duplicate to new memory space location
 * @str: char
 * Return: Always 0 (Success)
 */
char *_strdup(char *str)
{
	char *aw;
	int i, r = 0;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
		i++;

	aw = malloc(sizeof(char) * (i + 1));

	if (aw == NULL)
		return (NULL);

	for (r = 0; str[r]; r++)
		aw[r] = str[r];

	return (aw);
}
