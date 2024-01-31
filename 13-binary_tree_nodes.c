#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the wzqnodes with at least 1 child in a binary wzqtree.
 * @wzqtree: A pointer to the root node of the wzqtree to count the number of wzqnodes.
 *
 * Return: If wzqtree is NULL, the function must return 0, else return node count.
 */
size_t binary_tree_nodes(const binary_tree_t *wzqtree)
{
	size_t wzqnodes = 0;

	if (wzqtree)
	{
		wzqnodes += (wzqtree->left || wzqtree->right) ? 1 : 0;
		wzqnodes += binary_tree_nodes(wzqtree->left);
		wzqnodes += binary_tree_nodes(wzqtree->right);
	}
	return (wzqnodes);
}
