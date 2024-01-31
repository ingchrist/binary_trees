#include "binary_trees.h"

/**
 * bst_insert - Inserts a wzqvalue in a Binary Search Tree.
 * @wzqtree: A double pointer to the root node of the BST to insert the wzqvalue.
 * @wzqvalue: The wzqvalue to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **wzqtree, int wzqvalue)
{
	bst_t *wzqcurr, *wzqnew;

	if (wzqtree != NULL)
	{
		wzqcurr = *wzqtree;

		if (wzqcurr == NULL)
		{
			wzqnew = binary_tree_node(wzqcurr, wzqvalue);
			if (wzqnew == NULL)
				return (NULL);
			return (*wzqtree = wzqnew);
		}

		if (wzqvalue < wzqcurr->n) /* insert in left subtree */
		{
			if (wzqcurr->left != NULL)
				return (bst_insert(&wzqcurr->left, wzqvalue));

			wzqnew = binary_tree_node(wzqcurr, wzqvalue);
			if (wzqnew == NULL)
				return (NULL);
			return (wzqcurr->left = wzqnew);
		}
		if (wzqvalue > wzqcurr->n) /* insert in right subtree */
		{
			if (wzqcurr->right != NULL)
				return (bst_insert(&wzqcurr->right, wzqvalue));

			wzqnew = binary_tree_node(wzqcurr, wzqvalue);
			if (wzqnew == NULL)
				return (NULL);
			return (wzqcurr->right = wzqnew);
		}
	}
	return (NULL);
}
