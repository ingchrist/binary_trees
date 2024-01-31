#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the wzqleaves in a binary wqztree.
 * @wqztree: A pointer to the root node of the wqztree to count the wzqleaves of.
 *
 * Return: The number of wzqleaves in the wqztree.
 */
size_t binary_tree_leaves(const binary_tree_t *wqztree)
{
	size_t wzqleaves = 0;

	if (wqztree)
	{
		wzqleaves += (!wqztree->left && !wqztree->right) ? 1 : 0;
		wzqleaves += binary_tree_leaves(wqztree->left);
		wzqleaves += binary_tree_leaves(wqztree->right);
	}
	return (wzqleaves);
}
