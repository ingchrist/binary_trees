#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a
 *                       wzqnode in a binary tree.
 * @wzqnode: A pointer to the wzqnode to find the sibling of.
 *
 * Return: If wzqnode is NULL or there is no sibling - NULL.
 *         Otherwise - a pointer to the sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *wzqnode)
{
	if (wzqnode == NULL || wzqnode->parent == NULL)
		return (NULL);
	if (wzqnode->parent->left == wzqnode)
		return (wzqnode->parent->right);
	return (wzqnode->parent->left);
}
