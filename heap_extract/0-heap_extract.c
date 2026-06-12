#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_size - Counts the nodes in a binary heap
 * @root: Pointer to the root node of the heap
 *
 * Return: Number of nodes in the heap
 */
static size_t heap_size(const heap_t *root)
{
	if (root == NULL)
		return (0);

	return (1 + heap_size(root->left) + heap_size(root->right));
}

/**
 * node_at_index - Finds a node by its level-order index
 * @root: Pointer to the root node of the heap
 * @index: 1-based level-order index of the node to find
 *
 * Return: Pointer to the node at index
 */
static heap_t *node_at_index(heap_t *root, size_t index)
{
	heap_t *parent;

	if (index == 1)
		return (root);

	parent = node_at_index(root, index / 2);
	if (index % 2 == 0)
		return (parent->left);
	return (parent->right);
}

/**
 * heapify_down - Restores the max heap property from the root down
 * @root: Pointer to the root node of the heap
 */
static void heapify_down(heap_t *root)
{
	heap_t *largest;
	int tmp;

	while (root != NULL)
	{
		largest = root;
		if (root->left != NULL && root->left->n > largest->n)
			largest = root->left;
		if (root->right != NULL && root->right->n > largest->n)
			largest = root->right;
		if (largest == root)
			return;

		tmp = root->n;
		root->n = largest->n;
		largest->n = tmp;
		root = largest;
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the extracted root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *old_root, *last, *left, *right;
	size_t size;
	int value;

	if (root == NULL || *root == NULL)
		return (0);

	old_root = *root;
	value = old_root->n;
	size = heap_size(old_root);
	if (size == 1)
	{
		free(old_root);
		*root = NULL;
		return (value);
	}

	last = node_at_index(old_root, size);
	left = old_root->left;
	right = old_root->right;
	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	last->parent = NULL;
	last->left = (left == last) ? NULL : left;
	last->right = (right == last) ? NULL : right;
	if (last->left != NULL)
		last->left->parent = last;
	if (last->right != NULL)
		last->right->parent = last;

	free(old_root);
	*root = last;
	heapify_down(*root);

	return (value);
}
