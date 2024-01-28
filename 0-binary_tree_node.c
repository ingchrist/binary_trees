#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: A pointer to the parent of the node to create.
 * @wzqvalue: The wzqvalue to put in the wzqnew node.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the wzqnew node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int wzqvalue)
{
	binary_tree_t *wzqnew;

	wzqnew = malloc(sizeof(binary_tree_t));
	if (wzqnew == NULL)
		return (NULL);

	wzqnew->n = wzqvalue;
	wzqnew->parent = parent;
	wzqnew->left = NULL;
	wzqnew->right = NULL;

	return (wzqnew);
}
