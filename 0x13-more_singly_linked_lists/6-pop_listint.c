#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - deletes the head node of a link list_t list
 * @head: pointer to first node in the list
 *
 * Return: the head's node data
 */

int pop_listint(listint_t **head)
{
	listint_t *holder;
	int data;

	if (!head || !*head)
		return (0);

	data = (*head)->n;
	holder = (*head)->next;
	free(*head);
	*head = holder;

	return (data);
}
