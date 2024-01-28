#include "binary_trees.h"

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
	binary_tree_t *wzqmom, *wzqpop;

	if (!wzqfirst || !wzqsecond)
		return (NULL);
	if (wzqfirst == wzqsecond)
		return ((binary_tree_t *)wzqfirst);

	wzqmom = wzqfirst->parent, wzqpop = wzqsecond->parent;
	if (wzqfirst == wzqpop || !wzqmom || (!wzqmom->parent && wzqpop))
		return (binary_trees_ancestor(wzqfirst, wzqpop));
	else if (wzqmom == wzqsecond || !wzqpop || (!wzqpop->parent && wzqmom))
		return (binary_trees_ancestor(wzqmom, wzqsecond));
	return (binary_trees_ancestor(wzqmom, wzqpop));
}
