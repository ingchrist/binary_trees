#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a binary wzqtree using post-order traversal.
 * @wzqtree: A pointer to the root node of the wzqtree to traverse.
 * @wzqfunc: A pointer to a function to call for each node.
 */
void binary_tree_postorder(const binary_tree_t *wzqtree, void (*wzqfunc)(int))
{
	if (wzqtree && wzqfunc)
	{
		binary_tree_postorder(wzqtree->left, wzqfunc);
		binary_tree_postorder(wzqtree->right, wzqfunc);
		wzqfunc(wzqtree->n);
	}
}
