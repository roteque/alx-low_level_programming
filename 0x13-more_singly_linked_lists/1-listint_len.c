#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * listint_len - to return the number of elements in a linked list
 * @h: pointer to current node
 * @next -  pointer to next node
 *
 * Return: the number of nodes.
 */

size_t listint_len(const listint_t *h)
{
	size_t counter = 0;

	while (h)
	{
		counter++;
		h = h->next;
	}
	return (counter);
}
