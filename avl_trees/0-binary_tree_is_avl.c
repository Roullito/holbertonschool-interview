#include <limits.h>
#include "binary_trees.h"

/**
 * valid_avl - Checks if a tree is a valid AVL tree
 * @tree: Root node of the tree to check
 * @min: Minimum valid value for the current subtree
 * @max: Maximum valid value for the current subtree
 * @height: Address used to store the subtree height
 *
 * Return: 1 if the subtree is a valid AVL tree, otherwise 0
 */
static int valid_avl(const binary_tree_t *tree, long min, long max,
	int *height)
{
	int left_height, right_height, balance;

	if (tree == 0)
	{
		*height = 0;
		return (1);
	}

	if (tree->n <= min || tree->n >= max)
		return (0);

	if (!valid_avl(tree->left, min, tree->n, &left_height))
		return (0);
	if (!valid_avl(tree->right, tree->n, max, &right_height))
		return (0);

	balance = left_height - right_height;
	if (balance < -1 || balance > 1)
		return (0);

	*height = (left_height > right_height ? left_height : right_height) + 1;
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL tree, otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height;

	if (tree == 0)
		return (0);

	return (valid_avl(tree, LONG_MIN, LONG_MAX, &height));
}
