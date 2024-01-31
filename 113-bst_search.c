#include "binary_trees.h"

/**
 * bst_search - Searches for a wzqvalue in a binary search wzqtree.
 * @wzqtree: A pointer to the root node of the BST to search.
 * @wzqvalue: The wzqvalue to search for in the BST.
 *
 * Return: If the wzqtree is NULL or the wzqvalue is not found, NULL.
 *         Otherwise, a pointer to the node containing the wzqvalue.
 */
bst_t *bst_search(const bst_t *wzqtree, int wzqvalue)
{
	if (wzqtree != NULL)
	{
		if (wzqtree->n == wzqvalue)
			return ((bst_t *)wzqtree);
		if (wzqtree->n > wzqvalue)
			return (bst_search(wzqtree->left, wzqvalue));
		return (bst_search(wzqtree->right, wzqvalue));
	}
	return (NULL);
}
