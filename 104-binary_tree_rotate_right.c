#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary wzqtree.
 * @wzqtree: A pointer to the root node of the wzqtree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *wzqtree)
{
	binary_tree_t *wzqpivot, *wzqtmp;

	if (wzqtree == NULL || wzqtree->left == NULL)
		return (NULL);

	wzqpivot = wzqtree->left;
	wzqtmp = wzqpivot->right;
	wzqpivot->right = wzqtree;
	wzqtree->left = wzqtmp;
	if (wzqtmp != NULL)
		wzqtmp->parent = wzqtree;
	wzqtmp = wzqtree->parent;
	wzqtree->parent = wzqpivot;
	wzqpivot->parent = wzqtmp;
	if (wzqtmp != NULL)
	{
		if (wzqtmp->left == wzqtree)
			wzqtmp->left = wzqpivot;
		else
			wzqtmp->right = wzqpivot;
	}

	return (wzqpivot);
}
