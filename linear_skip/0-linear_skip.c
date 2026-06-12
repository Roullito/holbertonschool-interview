#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *start, *end;

	if (list == NULL)
		return (NULL);

	start = list;
	end = list->express;
	while (end != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       (unsigned long)end->index, end->n);
		if (end->n >= value)
			break;
		start = end;
		end = end->express;
	}

	if (end == NULL)
	{
		end = start;
		while (end->next != NULL)
			end = end->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       (unsigned long)start->index, (unsigned long)end->index);

	while (start != NULL && start->index <= end->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       (unsigned long)start->index, start->n);
		if (start->n == value)
			return (start);
		start = start->next;
	}

	return (NULL);
}
