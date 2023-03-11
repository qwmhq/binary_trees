#include "binary_trees.h"

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
 * binary_tree_min - find the smallest number in a binary tree
 *
 * @tree: pointer to the root node of the tree
 * Return: the smallest number in the binary tree, or INT_MAX
 *			if tree is null
 */
int binary_tree_min(const binary_tree_t *tree)
{
	int min, left_min, right_min;

	if (!tree)
		return (INT_MAX);
	min = tree->n;
	left_min = binary_tree_min(tree->left);
	right_min = binary_tree_min(tree->right);
	if (left_min < min)
		min = left_min;
	if (right_min < min)
		min = right_min;
	return (min);
}

/**
 * binary_tree_max - find the largest number in a binary tree
 *
 * @tree: pointer to the root node of the tree
 * Return: the largest number in the binary tree, or INT_MIN
 *			if tree is null
 */
int binary_tree_max(const binary_tree_t *tree)
{
	int max, left_max, right_max;

	if (!tree)
		return (INT_MIN);
	max = tree->n;
	left_max = binary_tree_max(tree->left);
	right_max = binary_tree_max(tree->right);
	if (left_max > max)
		max = left_max;
	if (right_max > max)
		max = right_max;
	return (max);
}

/**
 * binary_tree_is_bst - check if a binary tree is
 * a valid binary search tree (BST)
 *
 * @tree: pointer to the root node of the tree
 * Return: 1 if tree is a valid BST, or 0 if tree is NULL
 *			or not a valid BST
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int left_bst, right_bst;
	int left_max, right_min;

	left_max = binary_tree_max(tree->left);
	right_min = binary_tree_min(tree->right);
	if (!tree
			|| (tree->left && left_max > tree->n)
			|| (tree->right && right_min < tree->n))
		return (0);
	if ((binary_tree_is_leaf(tree->left) && binary_tree_is_leaf(tree->right))
			|| (binary_tree_is_leaf(tree->left) && !tree->right)
			|| (!tree->left && binary_tree_is_leaf(tree->right)))
		return (1);
	left_bst = binary_tree_is_bst(tree->left);
	right_bst = binary_tree_is_bst(tree->right);
	return (left_bst && right_bst);
}
