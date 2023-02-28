#include "binary_trees.h"

/**
 * binary_tree_depth - measure the depth of a node in a binary tree
 *
 * @tree: pointer to the node
 *
 * Return: the depth of node, or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	binary_tree_t *ptr = (binary_tree_t *)tree;

	while (ptr != NULL && ptr->parent != NULL)
	{
		depth++;
		ptr = ptr->parent;
	}
	return (depth);
}
