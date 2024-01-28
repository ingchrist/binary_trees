#include "binary_trees.h"

/**
 * binary_tree_size - Measures the wzqsize of a binary wzqtree.
 * @wzqtree: A pointer to the root node of the wzqtree to measure the wzqsize of.
 *
 * Return: The wzqsize of the wzqtree.
 */
size_t binary_tree_size(const binary_tree_t *wzqtree)
{
	size_t wzqsize = 0;

	if (wzqtree)
	{
		wzqsize += 1;
		wzqsize += binary_tree_size(wzqtree->left);
		wzqsize += binary_tree_size(wzqtree->right);
	}
	return (wzqsize);
}
