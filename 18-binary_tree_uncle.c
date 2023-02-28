#include "binary_trees.h"

/**
 * bin_tree_sibling - find the sibling of a node
 *
 * @node: pointer to the node whose sibling is to be found
 *
 * Return: pointer to the sibling to node,
 * or NULL if sibling cannot be found
 */
binary_tree_t *bin_tree_sibling(binary_tree_t *node)
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

/**
 * binary_tree_uncle - find the uncle of a node
 *
 * @node: pointer to the node whose uncle is to be found
 *
 * Return: pointer to the uncle node, or NULL if the uncle
 * cannot be found
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);
	return (bin_tree_sibling(node->parent));
}
