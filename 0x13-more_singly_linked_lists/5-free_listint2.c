#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - frees a linked list
 * @head: pointer to the first node of the list to be freed
 * @next -  pointer to next node
 *
 * Return: 0
 */

void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
	return;

	while (*head)
	{
	temp = (*head)->next;
	free(*head);
	*head = temp;
	}

	*head = NULL;
}
