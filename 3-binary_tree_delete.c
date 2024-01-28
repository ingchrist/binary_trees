#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes a binary wzqtree.
 * @wzqtree: A pointer to the root node of the wzqtree to delete.
 */
void binary_tree_delete(binary_tree_t *wzqtree)
{
	if (wzqtree != NULL)
	{
		binary_tree_delete(wzqtree->left);
		binary_tree_delete(wzqtree->right);
		free(wzqtree);
	}
}
