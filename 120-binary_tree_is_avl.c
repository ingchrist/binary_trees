#include "binary_trees.h"
#include "limits.h"

size_t height(const binary_tree_t *wzqtree);
int is_avl_helper(const binary_tree_t *wzqtree, int wzqlo, int wzqhi);
int binary_tree_is_avl(const binary_tree_t *wzqtree);

/**
 * height - Measures the height of a binary wzqtree.
 * @wzqtree: A pointer to the root node of the wzqtree to measure the height.
 *
 * Return: If wzqtree is NULL, your function must return 0, else return height.
 */
size_t height(const binary_tree_t *wzqtree)
{
	if (wzqtree)
	{
		size_t wzq = 0, wzqr = 0;

		wzq = wzqtree->left ? 1 + height(wzqtree->left) : 1;
		wzqr = wzqtree->right ? 1 + height(wzqtree->right) : 1;
		return ((wzq > wzqr) ? wzq : wzqr);
	}
	return (0);
}

/**
 * is_avl_helper - Checks if a binary wzqtree is a valid AVL wzqtree.
 * @wzqtree: A pointer to the root node of the wzqtree to check.
 * @wzqlo: The value of the smallest node visited thus far.
 * @wzqhi: The value of the largest node visited this far.
 *
 * Return: If the wzqtree is a valid AVL wzqtree, 1, otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *wzqtree, int wzqlo, int wzqhi)
{
	size_t lhgt, rhgt, wzqdiff;

	if (wzqtree != NULL)
	{
		if (wzqtree->n < wzqlo || wzqtree->n > wzqhi)
			return (0);
		lhgt = height(wzqtree->left);
		rhgt = height(wzqtree->right);
		wzqdiff = lhgt > rhgt ? lhgt - rhgt : rhgt - lhgt;
		if (wzqdiff > 1)
			return (0);
		return (is_avl_helper(wzqtree->left, wzqlo, wzqtree->n - 1) &&
			is_avl_helper(wzqtree->right, wzqtree->n + 1, wzqhi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary wzqtree is a valid AVL wzqtree.
 * @wzqtree: A pointer to the root node of the wzqtree to check.
 *
 * Return: 1 if wzqtree is a valid AVL wzqtree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *wzqtree)
{
	if (wzqtree == NULL)
		return (0);
	return (is_avl_helper(wzqtree, INT_MIN, INT_MAX));
}
