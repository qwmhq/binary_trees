#include "binary_trees.h"

/**
 * is_leaf - check if a node is a leaf
 *
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a leaf, or 0 if node is NULL or not a leaf
 */
int is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);
	return (1);
}

/**
 * binary_tree_leaves - count the leaves in a binary tree
 *
 * @tree: the root node of the tree
 *
 * Return: the number of leaves in the tree, or 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	if (is_leaf(tree))
		return (1);
	left = is_leaf(tree->left) ? 1 : binary_tree_leaves(tree->left);
	right = is_leaf(tree->right) ? 1 : binary_tree_leaves(tree->right);
	return (left + right);
}
