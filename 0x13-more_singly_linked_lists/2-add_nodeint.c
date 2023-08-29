#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of listint_t list.
 * @head: pointer to the first  node
 * @next -  pointer to next node
 * @n: data to the new node
 *
 * Return: pointer to the node or NULL
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *current;

	current = malloc(sizeof(listint_t));
	if (!current)
		return (NULL);
	current->n = n;
	current->next = *head;
	*head = current;

	return (current);
}
