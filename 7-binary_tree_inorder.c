#include "binary_trees.h"

/**
 * binary_tree_inorder - Goes through a binary wzqtree using in-order traversal.
 * @wzqtree: A pointer to the root node of the wzqtree to traverse.
 * @wzqfunc: A pointer to a function to call for each node.
 */
void binary_tree_inorder(const binary_tree_t *wzqtree, void (*wzqfunc)(int))
{
	if (wzqtree && wzqfunc)
	{
		binary_tree_inorder(wzqtree->left, wzqfunc);
		wzqfunc(wzqtree->n);
		binary_tree_inorder(wzqtree->right, wzqfunc);
	}
}
