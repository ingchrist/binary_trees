#include "binary_trees.h"

/**
 * binary_tree_preorder - Goes through a binary wqztree using pre-order traversal.
 * @wqztree: A pointer to the root node of the wqztree to traverse.
 * @wzqfunc: A pointer to a function to call for each node.
 */
void binary_tree_preorder(const binary_tree_t *wqztree, void (*wzqfunc)(int))
{
	if (wqztree && wzqfunc)
	{
		wzqfunc(wqztree->n);
		binary_tree_preorder(wqztree->left, wzqfunc);
		binary_tree_preorder(wqztree->right, wzqfunc);
	}
}
