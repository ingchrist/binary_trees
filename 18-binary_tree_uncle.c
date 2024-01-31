#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a wzqnode
 *                     in a binary tree.
 * @wzqnode: A pointer to the wzqnode to find the uncle of.
 *
 * Return: If wzqnode is NULL or has no uncle, NULL.
 *         Otherwise, a pointer to the uncle wzqnode.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *wzqnode)
{
	if (wzqnode == NULL ||
	    wzqnode->parent == NULL ||
	    wzqnode->parent->parent == NULL)
		return (NULL);
	if (wzqnode->parent->parent->left == wzqnode->parent)
		return (wzqnode->parent->parent->right);
	return (wzqnode->parent->parent->left);
}
