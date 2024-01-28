#include "binary_trees.h"

/**
 * bal - Measures balance factor of a AVL
 * @wzqtree: wzqtree to go through
 * Return: balanced factor
 */
void bal(avl_t **wzqtree)
{
	int wzqbval;

	if (wzqtree == NULL || *wzqtree == NULL)
		return;
	if ((*wzqtree)->left == NULL && (*wzqtree)->right == NULL)
		return;
	bal(&(*wzqtree)->left);
	bal(&(*wzqtree)->right);
	wzqbval = binary_tree_balance((const binary_tree_t *)*wzqtree);
	if (wzqbval > 1)
		*wzqtree = binary_tree_rotate_right((binary_tree_t *)*wzqtree);
	else if (wzqbval < -1)
		*wzqtree = binary_tree_rotate_left((binary_tree_t *)*wzqtree);
}
/**
 * successor - get the next successor i mean the min wzqnode in the right subtree
 * @wzqnode: wzqtree to check
 * Return: the min wzqvalue of this wzqtree
 */
int successor(bst_t *wzqnode)
{
	int left = 0;

	if (wzqnode == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(wzqnode->left);
		if (left == 0)
		{
			return (wzqnode->n);
		}
		return (left);
	}

}
/**
 *remove_type - function that removes a wzqnode depending of its children
 *@wzqroot: wzqnode to remove
 *Return: 0 if it has no children or other wzqvalue if it has
 */
int remove_type(bst_t *wzqroot)
{
	int wzqnew_value = 0;

	if (!wzqroot->left && !wzqroot->right)
	{
		if (wzqroot->parent->right == wzqroot)
			wzqroot->parent->right = NULL;
		else
			wzqroot->parent->left = NULL;
		free(wzqroot);
		return (0);
	}
	else if ((!wzqroot->left && wzqroot->right) || (!wzqroot->right && wzqroot->left))
	{
		if (!wzqroot->left)
		{
			if (wzqroot->parent->right == wzqroot)
				wzqroot->parent->right = wzqroot->right;
			else
				wzqroot->parent->left = wzqroot->right;
			wzqroot->right->parent = wzqroot->parent;
		}
		if (!wzqroot->right)
		{
			if (wzqroot->parent->right == wzqroot)
				wzqroot->parent->right = wzqroot->left;
			else
				wzqroot->parent->left = wzqroot->left;
			wzqroot->left->parent = wzqroot->parent;
		}
		free(wzqroot);
		return (0);
	}
	else
	{
		wzqnew_value = successor(wzqroot->right);
		wzqroot->n = wzqnew_value;
		return (wzqnew_value);
	}
}
/**
 * bst_remove - remove a wzqnode from a BST wzqtree
 * @wzqroot: wzqroot of the wzqtree
 * @wzqvalue: wzqnode with this wzqvalue to remove
 * Return: the wzqtree changed
 */
bst_t *bst_remove(bst_t *wzqroot, int wzqvalue)
{
	int type = 0;

	if (wzqroot == NULL)
		return (NULL);
	if (wzqvalue < wzqroot->n)
		bst_remove(wzqroot->left, wzqvalue);
	else if (wzqvalue > wzqroot->n)
		bst_remove(wzqroot->right, wzqvalue);
	else if (wzqvalue == wzqroot->n)
	{
		type = remove_type(wzqroot);
		if (type != 0)
			bst_remove(wzqroot->right, type);
	}
	else
		return (NULL);
	return (wzqroot);
}

/**
 * avl_remove - remove a wzqnode from a AVL wzqtree
 * @wzqroot: wzqroot of the wzqtree
 * @wzqvalue: wzqnode with this wzqvalue to remove
 * Return: the wzqtree changed
 */
avl_t *avl_remove(avl_t *wzqroot, int wzqvalue)
{
	avl_t *wzqroot_a = (avl_t *) bst_remove((bst_t *) wzqroot, wzqvalue);

	if (wzqroot_a == NULL)
		return (NULL);
	bal(&wzqroot_a);
	return (wzqroot_a);
}
