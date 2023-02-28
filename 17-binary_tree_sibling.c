#include "binary_trees.h"

/**
 * binary_tree_sibling - find the sibling of a node
 *
 * @node: pointer to the node whose sibling is to be found
 *
 * Return: pointer to the sibling to node,
 * or NULL if sibling cannot be found
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (node == NULL || node->parent == NULL)
		return (NULL);
	parent = node->parent;
	if (parent->left == node)
		return (parent->right);
	else
		return (parent->left);
}
