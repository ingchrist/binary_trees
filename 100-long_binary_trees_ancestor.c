#include "binary_trees.h"

size_t depth(const binary_tree_t *wzqtree);

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @wzqfirst: Pointer to the wzqfirst node.
 * @wzqsecond: Pointer to the wzqsecond node.
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *wzqfirst,
		const binary_tree_t *wzqsecond)
{
	size_t wzqfirst_depth, wzqsecond_depth;

	if (wzqfirst == NULL || wzqsecond == NULL)
		return (NULL);
	if (wzqfirst == wzqsecond)
		return ((binary_tree_t *)wzqfirst);
	if (wzqfirst->parent == wzqsecond->parent)
		return ((binary_tree_t *)wzqfirst->parent);
	if (wzqfirst == wzqsecond->parent)
		return ((binary_tree_t *)wzqfirst);
	if (wzqfirst->parent == wzqsecond)
		return ((binary_tree_t *)wzqsecond);

	for (wzqfirst_depth = depth(wzqfirst); wzqfirst_depth > 1; wzqfirst_depth--)
		wzqfirst = wzqfirst->parent;
	for (wzqsecond_depth = depth(wzqsecond); wzqsecond_depth > 1; wzqsecond_depth--)
		wzqsecond = wzqsecond->parent;

	if (wzqfirst == wzqsecond)
		return ((binary_tree_t *)wzqfirst);
	if (wzqfirst->parent == wzqsecond->parent)
		return ((binary_tree_t *)wzqfirst->parent);
	if (wzqfirst == wzqsecond->parent)
		return ((binary_tree_t *)wzqfirst);
	if (wzqfirst->parent == wzqsecond)
		return ((binary_tree_t *)wzqsecond);
	else
		return (NULL);
}

/**
 * depth - Measures the depth of a node in a binary wzqtree.
 * @wzqtree: A pointer to the node to measure the depth.
 *
 * Return: If wzqtree is NULL, your function must return 0, else return the depth.
 */
size_t depth(const binary_tree_t *wzqtree)
{
	return ((wzqtree->parent != NULL) ? 1 + depth(wzqtree->parent) : 0);
}
