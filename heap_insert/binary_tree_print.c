#include <stdio.h>
#include "binary_trees.h"

/**
 * print_tree - Prints a binary tree sideways
 * @tree: Pointer to the current node
 * @space: Current indentation level
 */
static void print_tree(const binary_tree_t *tree, int space)
{
	if (tree == NULL)
		return;

	print_tree(tree->right, space + 6);
	printf("%*s(%03d)\n", space, "", tree->n);
	print_tree(tree->left, space + 6);
}

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to the root node
 */
void binary_tree_print(const binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	print_tree(tree, 0);
}
