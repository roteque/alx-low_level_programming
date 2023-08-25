#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a linked list
 * @h: element to print
 * @str - string
 * @next - points to the next node
 *
 * Return: the length of the string
 */

size_t print_list(const list_t *h)
{
	size_t count = 0;

	while  (h)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		h = h->next;
		count++;
	}
	return (count);
}
