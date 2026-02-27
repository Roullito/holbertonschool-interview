#include "binary_trees.h"

/**
 * tree_size - Counts nodes in a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Number of nodes in the tree
 */
static size_t tree_size(const heap_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * insert_parent - Finds the parent where the next node must be inserted
 * @root: Pointer to the heap root
 * @index: Index (1-based) of the node to insert in a complete tree
 *
 * Return: Parent pointer, or NULL on failure
 */
static heap_t *insert_parent(heap_t *root, size_t index)
{
	size_t parent_index, mask;
	heap_t *node;

	if (root == NULL || index < 2)
		return (NULL);

	parent_index = index >> 1;
	mask = 1;
	while (mask <= parent_index)
		mask <<= 1;
	mask >>= 2;

	node = root;
	while (mask > 0 && node != NULL)
	{
		if (parent_index & mask)
			node = node->right;
		else
			node = node->left;
		mask >>= 1;
	}

	return (node);
}

/**
 * heapify_up - Restores Max Heap order after insertion
 * @node: Pointer to newly inserted node
 *
 * Return: Pointer to the node holding the inserted value
 */
static heap_t *heapify_up(heap_t *node)
{
	int tmp;

	while (node->parent != NULL && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}

	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the heap root
 * @value: Value to insert
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent, *node;
	size_t index;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	index = tree_size(*root) + 1;
	parent = insert_parent(*root, index);
	if (parent == NULL)
		return (NULL);

	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);

	if ((index & 1) == 0)
		parent->left = node;
	else
		parent->right = node;

	return (heapify_up(node));
}
