#include "lists.h"

/**
 * reverse_list - Reverses a singly linked list
 * @head: Head of the list to reverse
 *
 * Return: New head of the reversed list
 */
static listint_t *reverse_list(listint_t *head)
{
	listint_t *prev, *next;

	prev = NULL;
	while (head != NULL)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}

	return (prev);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Address of pointer to head node
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow, *fast, *first_half_end;
	listint_t *second_half_start, *left, *right;
	int result;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return (1);

	slow = *head;
	fast = *head;
	while (fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	first_half_end = slow;
	second_half_start = reverse_list(first_half_end->next);

	result = 1;
	left = *head;
	right = second_half_start;
	while (right != NULL)
	{
		if (left->n != right->n)
		{
			result = 0;
			break;
		}
		left = left->next;
		right = right->next;
	}

	first_half_end->next = reverse_list(second_half_start);
	return (result);
}
