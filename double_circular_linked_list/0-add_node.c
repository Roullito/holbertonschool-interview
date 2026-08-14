#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * create_node - Creates a new circular list node
 * @str: String to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
static List *create_node(char *str)
{
	List *node;

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);

	node->str = strdup(str);
	if (node->str == NULL)
	{
		free(node);
		return (NULL);
	}

	node->prev = node;
	node->next = node;
	return (node);
}

/**
 * add_node_end - Adds a new node at the end of a double circular linked list
 * @list: Address of the list to modify
 * @str: String to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *node, *tail;

	if (list == NULL || str == NULL)
		return (NULL);

	node = create_node(str);
	if (node == NULL)
		return (NULL);

	if (*list == NULL)
	{
		*list = node;
		return (node);
	}

	tail = (*list)->prev;
	node->next = *list;
	node->prev = tail;
	tail->next = node;
	(*list)->prev = node;

	return (node);
}

/**
 * add_node_begin - Adds a node at the start of a double circular linked list
 * @list: Address of the list to modify
 * @str: String to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *node;

	node = add_node_end(list, str);
	if (node == NULL)
		return (NULL);

	*list = node;
	return (node);
}
