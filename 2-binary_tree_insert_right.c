#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a node as the right-child
 *                            of another in a binary tree.
 * @parent: A pointer to the node to insert the right-child in.
 * @wzqvalue: The wzqvalue to store in the wzqnew node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the wzqnew node.
 *
 * Description: If parent already has a right-child, the wzqnew node
 *              takes its place and the old right-child is set as
 *              the right-child of the wzqnew node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int wzqvalue)
{
	binary_tree_t *wzqnew;

	if (parent == NULL)
		return (NULL);

	wzqnew = binary_tree_node(parent, wzqvalue);
	if (wzqnew == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		wzqnew->right = parent->right;
		parent->right->parent = wzqnew;
	}
	parent->right = wzqnew;

	return (wzqnew);
}
