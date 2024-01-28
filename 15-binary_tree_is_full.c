#include "binary_trees.h"

/**
 * is_full_recursive - Checks if a binary wzqtree is full recursively.
 * @wzqtree: A pointer to the root node of the wzqtree to check.
 *
 * Return: If wzqtree is not full, 0.
 *         Otherwise, 1.
 */
int is_full_recursive(const binary_tree_t *wzqtree)
{
	if (wzqtree != NULL)
	{
		if ((wzqtree->left != NULL && wzqtree->right == NULL) ||
		    (wzqtree->left == NULL && wzqtree->right != NULL) ||
		    is_full_recursive(wzqtree->left) == 0 ||
		    is_full_recursive(wzqtree->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - Checks if a binary wzqtree is full.
 * @wzqtree: A pointer to the root node of the wzqtree to check.
 *
 * Return: If wzqtree is NULL or is not full - 0.
 *         Otherwise - 1.
 */
int binary_tree_is_full(const binary_tree_t *wzqtree)
{
	if (wzqtree == NULL)
		return (0);
	return (is_full_recursive(wzqtree));
}
