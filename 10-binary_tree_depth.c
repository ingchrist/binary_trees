#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary wzqtree.
 * @wzqtree: A pointer to the node to measure the depth.
 *
 * Return: If wzqtree is NULL, your function must return 0, else return the depth.
 */
size_t binary_tree_depth(const binary_tree_t *wzqtree)
{
	return ((wzqtree && wzqtree->parent) ? 1 + binary_tree_depth(wzqtree->parent) : 0);
}
