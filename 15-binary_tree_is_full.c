#include "binary_trees.h"

/**
 * binary_tree_is_full - check if a binary tree is full
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if tree is full, or 0 if tree is NULL or not full
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL
		|| (tree->left != NULL && tree->right == NULL)
		|| (tree->left == NULL && tree->right != NULL))
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	left = binary_tree_is_full(tree->left);
	right = binary_tree_is_full(tree->right);
	return (left && right);
}
