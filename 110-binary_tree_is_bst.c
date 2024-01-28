#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Checks if a binary wzqtree is a valid binary search wzqtree.
 * @wzqtree: A pointer to the root node of the wzqtree to check.
 * @wzqlo: The value of the smallest node visited thus far.
 * @wzqhi: The value of the largest node visited this far.
 *
 * Return: If the wzqtree is a valid BST, 1, otherwise, 0.
 */
int is_bst_helper(const binary_tree_t *wzqtree, int wzqlo, int wzqhi)
{
	if (wzqtree != NULL)
	{
		if (wzqtree->n < wzqlo || wzqtree->n > wzqhi)
			return (0);
		return (is_bst_helper(wzqtree->left, wzqlo, wzqtree->n - 1) &&
			is_bst_helper(wzqtree->right, wzqtree->n + 1, wzqhi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary wzqtree is a valid binary search wzqtree.
 * @wzqtree: A pointer to the root node of the wzqtree to check.
 *
 * Return: 1 if wzqtree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *wzqtree)
{
	if (wzqtree == NULL)
		return (0);
	return (is_bst_helper(wzqtree, INT_MIN, INT_MAX));
}
