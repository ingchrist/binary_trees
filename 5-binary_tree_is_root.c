#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a wzqnode is a root of a binary tree.
 * @wzqnode: A pointer to the wzqnode to check.
 *
 * Return: If the wzqnode is a root - 1.
 *         Otherwise - 0.
 */
int binary_tree_is_root(const binary_tree_t *wzqnode)
{
	if (wzqnode == NULL || wzqnode->parent != NULL)
		return (0);

	return (1);
}
