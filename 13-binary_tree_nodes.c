#include "binary_trees.h"

/**
 * has_child - check if a binary tree node has at least one child
 *
 * @node: pointer to the node
 *
 * Return: 1 if node has at least one child, otherwise 0
 */
size_t has_child(const binary_tree_t *node)
{
	if (node != NULL && (node->left != NULL || node->right != NULL))
		return (1);
	return (0);
}

/**
 * binary_tree_nodes - count the nodes with at least 1 child
 * in a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: the number of nodes with at least 1 child in tree,
 * or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL || !has_child(tree))
		return (0);
	left = binary_tree_nodes(tree->left);
	right = binary_tree_nodes(tree->right);
	return (1 + left + right);
}
