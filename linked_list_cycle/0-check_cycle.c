#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - checks if a singly linked list contains a cycle
 * @list: pointer to the head of the linked list
 *
 * Return: 1 if the list contains a cycle, 0 otherwise
 */
int check_cycle(listint_t *list)
{
	listint_t *slow;
	listint_t *fast;

	slow = list;
	fast = list;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			return (1);
	}
	return (0);
}

