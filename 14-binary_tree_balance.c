#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary wzqtree.
 * @wzqtree: A pointer to the root node of the wzqtree to measure the balance factor.
 *
 * Return: If wzqtree is NULL, return 0, else return balance factor.
 */
int binary_tree_balance(const binary_tree_t *wzqtree)
{
	if (wzqtree)
		return (binary_tree_height(wzqtree->left) - binary_tree_height(wzqtree->right));

	return (0);
}

/**
 * binary_tree_height - Measures the height of a binary wzqtree.
 * @wzqtree: A pointer to the root node of the wzqtree to measure the height.
 *
 * Return: If wzqtree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *wzqtree)
{
	if (wzqtree)
	{
		size_t wzql = 0, wzq = 0;

		wzql = wzqtree->left ? 1 + binary_tree_height(wzqtree->left) : 1;
		wzq = wzqtree->right ? 1 + binary_tree_height(wzqtree->right) : 1;
		return ((wzql > wzq) ? wzql : wzq);
	}
	return (0);
}
