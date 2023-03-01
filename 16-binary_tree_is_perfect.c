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
 * binary_tree_is_perfect - check if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if tree is perfect, or 0 if tree is NULL or imperfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL
			|| (tree->left != NULL && tree->right == NULL)
			|| (tree->left == NULL && tree->right != NULL)
			|| (has_child(tree->left) && !has_child(tree->right))
			|| (!has_child(tree->left) && has_child(tree->right)))
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	left = binary_tree_is_perfect(tree->left);
	right = binary_tree_is_perfect(tree->right);
	return (left && right);
}
