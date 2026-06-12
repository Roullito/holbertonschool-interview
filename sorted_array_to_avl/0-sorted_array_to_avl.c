#include <stdlib.h>
#include "binary_trees.h"

/**
 * free_avl - Frees an AVL tree
 * @tree: Pointer to the root node of the tree to free
 */
static void free_avl(avl_t *tree)
{
	if (tree == NULL)
		return;

	free_avl(tree->left);
	free_avl(tree->right);
	free(tree);
}

/**
 * build_avl - Builds an AVL tree from a sorted array range
 * @array: Pointer to the first element of the sorted array
 * @start: First index of the range to use
 * @end: Index after the last element of the range to use
 * @parent: Parent node of the new subtree root
 * @failed: Allocation failure flag
 *
 * Return: Pointer to the subtree root, or NULL on failure
 */
static avl_t *build_avl(int *array, size_t start, size_t end,
			avl_t *parent, int *failed)
{
	avl_t *root;
	size_t middle;

	if (start >= end || *failed)
		return (NULL);

	middle = start + (end - start - 1) / 2;
	root = malloc(sizeof(avl_t));
	if (root == NULL)
	{
		*failed = 1;
		return (NULL);
	}

	root->n = array[middle];
	root->parent = parent;
	root->left = NULL;
	root->right = NULL;
	root->left = build_avl(array, start, middle, root, failed);
	root->right = build_avl(array, middle + 1, end, root, failed);
	if (*failed)
	{
		free_avl(root);
		return (NULL);
	}

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the sorted array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	int failed = 0;

	if (array == NULL || size == 0)
		return (NULL);

	return (build_avl(array, 0, size, NULL, &failed));
}
