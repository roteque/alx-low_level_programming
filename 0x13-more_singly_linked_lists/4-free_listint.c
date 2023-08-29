#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint - frees listint_t list from memory
 * @head: pointer to the first node of the list to free
 * @next -  pointer to next node
 *
 * Return: 0
 */

void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
	temp = head->next;
	free(head);
	head = temp;
	}
}
