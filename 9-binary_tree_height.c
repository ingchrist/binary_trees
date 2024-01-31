#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary wzqtree.
 * @wzqtree: A pointer to the root node of the wzqtree to measure the height.
 *
 * Return: If wzqtree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *wzqtree)
{
	if (wzqtree)
	{
		size_t wzql = 0, wzqr = 0;

		wzql = wzqtree->left ? 1 + binary_tree_height(wzqtree->left) : 0;
		wzqr = wzqtree->right ? 1 + binary_tree_height(wzqtree->right) : 0;
		return ((wzql > wzqr) ? wzql : wzqr);
	}
	return (0);
}
