#include "binary_trees.h"
#include <stdio.h>

#define COUNT 10

/* Helper to recursively print tree in 2D */
void print_tree(const binary_tree_t *tree, int space)
{
	int i;

	if (tree == NULL)
		return;

	space += COUNT;

	print_tree(tree->right, space);

	printf("\n");
	for (i = COUNT; i < space; i++)
		printf(" ");
	printf("%d\n", tree->n);

	print_tree(tree->left, space);
}

/**
 * binary_tree_print - Prints a binary tree visually
 * @tree: Pointer to root node
 */
void binary_tree_print(const binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	print_tree(tree, 0);
}
