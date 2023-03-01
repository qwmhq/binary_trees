#include "binary_trees.h"

/**
 * max - find the greater of two integers
 *
 * @n1: integer
 * @n2: integer
 *
 * Return: the greater value between n1 and n2
 */
size_t max(size_t n1, size_t n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

/**
 * binary_tree_height - measure the height of a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: the height of the binary tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	return (1 + max(left_height, right_height));
}

/**
 * binary_tree_balance - measure the balance factor of a tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: the balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);
	left_height = tree->left == NULL ?
					-1 : (int)binary_tree_height(tree->left);
	right_height = tree->right == NULL ?
					-1 : (int)binary_tree_height(tree->right);
	return (left_height - right_height);
}
