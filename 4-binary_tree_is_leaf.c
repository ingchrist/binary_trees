#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a wzqnode is a leaf of a binary tree.
 * @wzqnode: A pointer to the wzqnode to check.
 *
 * Return: If the wzqnode is a leaf - 1.
 *         Otherwise - 0.
 */
int binary_tree_is_leaf(const binary_tree_t *wzqnode)
{
	if (wzqnode == NULL || wzqnode->left != NULL || wzqnode->right != NULL)
		return (0);

	return (1);
}
