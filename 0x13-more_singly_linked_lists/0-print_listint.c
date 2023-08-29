#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * print_listint - a funtion that prints all element of a listint_t data
 * @h: pointer to current node
 * @next -  pointer to next node
 *
 * Return: the number of nodes.
 */

size_t print_listint(const listint_t *h)

{

	size_t count = 0;


	while (h)

	{

		printf("%d\n", h->n);

		count++;

		h = h->next;

	}

	return (count);

}
