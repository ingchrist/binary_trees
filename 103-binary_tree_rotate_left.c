#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary wzqtree.
 * @wzqtree: A pointer to the root node of the wzqtree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *wzqtree)
{
	binary_tree_t *wzqpivot, *wzqtmp;

	if (wzqtree == NULL || wzqtree->right == NULL)
		return (NULL);

	wzqpivot = wzqtree->right;
	wzqtmp = wzqpivot->left;
	wzqpivot->left = wzqtree;
	wzqtree->right = wzqtmp;
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
