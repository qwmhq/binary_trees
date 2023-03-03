#include "binary_trees.h"

/**
 * binary_tree_rotate_right - perform a left-rotation on a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: pointer to the new root node of the tree
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp;

	if (!tree)
		return (NULL);
	if (!tree->left)
		return (tree);
	temp = tree->left;
	tree->left = tree->left->right;
	if (tree->left)
		tree->left->parent = tree;
	tree->parent = temp;
	temp->right = tree;
	return (temp);
}
