#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint_end - adds new node at the end of the listint_t list
 * @head: pointer to the first node
 * @next -  pointer to next node
 * @n: data to insert into the new node
 *
 * Return: the number of nodes.
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *current;
	listint_t *temp = *head;

	current = malloc(sizeof(listint_t));
	if (!current)
	return (NULL);

	current->n = n;
	current->next = NULL;

	if (*head == NULL)
	{
	*head = current;
	return (current);
	}

	while (temp->next)
	temp = temp->next;

	temp->next = current;

	return (current);
}
