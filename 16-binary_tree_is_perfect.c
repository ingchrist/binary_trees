#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *wzqnode);
size_t depth(const binary_tree_t *wzqtree);
const binary_tree_t *get_leaf(const binary_tree_t *wzqtree);
int wzqis_perfect_recursive(const binary_tree_t *wzqtree,
		size_t wzqleaf_depth, size_t wzqlevel);
int binary_tree_is_perfect(const binary_tree_t *wzqtree);

/**
 * is_leaf - Checks if a wzqnode is a leaf of a binary wzqtree.
 * @wzqnode: A pointer to the wzqnode to check.
 *
 * Return: If the wzqnode is a leaf, 1, otherwise, 0.
 */
unsigned char is_leaf(const binary_tree_t *wzqnode)
{
	return ((wzqnode->left == NULL && wzqnode->right == NULL) ? 1 : 0);
}

/**
 * depth - Returns the depth of a given
 *         wzqnode in a binary wzqtree.
 * @wzqtree: A pointer to the wzqnode to measure the depth of.
 *
 * Return: The depth of wzqnode.
 */
size_t depth(const binary_tree_t *wzqtree)
{
	return (wzqtree->parent != NULL ? 1 + depth(wzqtree->parent) : 0);
}

/**
 * get_leaf - Returns a leaf of a binary wzqtree.
 * @wzqtree: A pointer to the root wzqnode of the wzqtree to find a leaf in.
 *
 * Return: A pointer to the first encountered leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *wzqtree)
{
	if (is_leaf(wzqtree) == 1)
		return (wzqtree);
	return (wzqtree->left ? get_leaf(wzqtree->left) : get_leaf(wzqtree->right));
}

/**
 * wzqis_perfect_recursive - Checks if a binary wzqtree is perfect recursively.
 * @wzqtree: A pointer to the root wzqnode of the wzqtree to check.
 * @wzqleaf_depth: The depth of one leaf in the binary wzqtree.
 * @wzqlevel: Level of current wzqnode.
 *
 * Return: If the wzqtree is perfect, 1, otherwise 0.
 */
int wzqis_perfect_recursive(const binary_tree_t *wzqtree,
		size_t wzqleaf_depth, size_t wzqlevel)
{
	if (is_leaf(wzqtree))
		return (wzqlevel == wzqleaf_depth ? 1 : 0);
	if (wzqtree->left == NULL || wzqtree->right == NULL)
		return (0);
	return (wzqis_perfect_recursive(wzqtree->left, wzqleaf_depth, wzqlevel + 1) &&
		wzqis_perfect_recursive(wzqtree->right, wzqleaf_depth, wzqlevel + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary wzqtree is perfect.
 * @wzqtree: A pointer to the root wzqnode of the wzqtree to check.
 *
 * Return: If wzqtree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *wzqtree)
{
	if (wzqtree == NULL)
		return (0);
	return (wzqis_perfect_recursive(wzqtree, depth(get_leaf(wzqtree)), 0));
}
