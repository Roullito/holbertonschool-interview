#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to pointer to the head of the list
 * @number: number to insert
 *
 * Return: address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *prev = NULL, *curr;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	curr = *head;

	/* insert at beginning (empty list or number <= head->n) */
	if (curr == NULL || curr->n >= number)
	{
		new->next = curr;
		*head = new;
		return (new);
	}

	/* find insertion point */
	while (curr != NULL && curr->n < number)
	{
		prev = curr;
		curr = curr->next;
	}

	/* insert between prev and curr */
	new->next = curr;
	prev->next = new;

	return (new);
}
