#include "binary_trees.h"

/**
 * binary_tree_rotate_left - perform a left-rotation on a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: pointer to the new root node of the tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp;

	if (!tree)
		return (NULL);
	if (!tree->right)
		return (tree);
	temp = tree->right;
	tree->right = tree->right->left;
	if (tree->right)
		tree->right->parent = tree;
	tree->parent = temp;
	temp->left = tree;
	return (temp);
}
