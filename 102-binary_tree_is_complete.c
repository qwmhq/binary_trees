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
 * binary_tree_is_leaf - check if a node is a leaf
 *
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a leaf, or 0 if node is NULL or not a leaf
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);
	return (1);
}

/**
 * binary_tree_is_complete - check if a binary tree is complete
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if tree is complete, or 0 if tree is NULL or incomplete
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int left_height, right_height, height_diff;
	int left_complete, right_complete;

	if (!tree || (!tree->left && tree->right)
			|| (tree->left && !tree->left->right && tree->right && tree->right->left))
		return (0);
	left_height = !tree->left ?
					-1 : (int)binary_tree_height(tree->left);
	right_height = !tree->right ?
					-1 : (int)binary_tree_height(tree->right);
	height_diff = left_height - right_height;
	if (height_diff != 0 && height_diff != 1)
		return (0);
	if ((binary_tree_is_leaf(tree->left) && binary_tree_is_leaf(tree->right))
			|| (binary_tree_is_leaf(tree->left) && !tree->right)
			|| (binary_tree_is_leaf(tree)))
		return (1);
	left_complete = binary_tree_is_complete(tree->left);
	right_complete = binary_tree_is_complete(tree->right);
	return (left_complete && right_complete);
}
