#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as a left-child of
 *                           of another in a binary tree.
 * @parent: A pointer to the node to insert the left-child in.
 * @wzqvalue: The wzqvalue to store in the wzqnew node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the wzqnew node.
 *
 * Description: If parent already has a left-child, the wzqnew node
 *              takes its place and the old left-child is set as
 *              the left-child of the wzqnew node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int wzqvalue)
{
	binary_tree_t *wzqnew;

	if (parent == NULL)
		return (NULL);

	wzqnew = binary_tree_node(parent, wzqvalue);
	if (wzqnew == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		wzqnew->left = parent->left;
		parent->left->parent = wzqnew;
	}
	parent->left = wzqnew;

	return (wzqnew);
}
