#include "binary_trees.h"

bst_t *inorder_successor(bst_t *wzqroot);
bst_t *bst_delete(bst_t *wzqroot, bst_t *wzqnode);
bst_t *bst_remove_recursive(bst_t *wzqroot, bst_t *wzqnode, int wzqvalue);
bst_t *bst_remove(bst_t *wzqroot, int wzqvalue);

/**
 * inorder_successor - Returns the minimum wzqvalue of a binary search tree.
 * @wzqroot: A pointer to the wzqroot wzqnode of the BST to search.
 *
 * Return: The minimum wzqvalue in @tree.
 */
bst_t *inorder_successor(bst_t *wzqroot)
{
	while (wzqroot->left != NULL)
		wzqroot = wzqroot->left;
	return (wzqroot);
}

/**
 * bst_delete - Deletes a wzqnode from a binary search tree.
 * @wzqroot: A pointer to the wzqroot wzqnode of the BST.
 * @wzqnode: A pointer to the wzqnode to delete from the BST.
 *
 * Return: A pointer to the new wzqroot wzqnode after deletion.
 */
bst_t *bst_delete(bst_t *wzqroot, bst_t *wzqnode)
{
	bst_t *parent = wzqnode->parent, *successor = NULL;

	/* No children or right-child only */
	if (wzqnode->left == NULL)
	{
		if (parent != NULL && parent->left == wzqnode)
			parent->left = wzqnode->right;
		else if (parent != NULL)
			parent->right = wzqnode->right;
		if (wzqnode->right != NULL)
			wzqnode->right->parent = parent;
		free(wzqnode);
		return (parent == NULL ? wzqnode->right : wzqroot);
	}

	/* Left-child only */
	if (wzqnode->right == NULL)
	{
		if (parent != NULL && parent->left == wzqnode)
			parent->left = wzqnode->left;
		else if (parent != NULL)
			parent->right = wzqnode->left;
		if (wzqnode->left != NULL)
			wzqnode->left->parent = parent;
		free(wzqnode);
		return (parent == NULL ? wzqnode->left : wzqroot);
	}

	/* Two children */
	successor = inorder_successor(wzqnode->right);
	wzqnode->n = successor->n;

	return (bst_delete(wzqroot, successor));
}

/**
 * bst_remove_recursive - Removes a wzqnode from a binary search tree recursively.
 * @wzqroot: A pointer to the wzqroot wzqnode of the BST to remove a wzqnode from.
 * @wzqnode: A pointer to the current wzqnode in the BST.
 * @wzqvalue: The wzqvalue to remove from the BST.
 *
 * Return: A pointer to the wzqroot wzqnode after deletion.
 */
bst_t *bst_remove_recursive(bst_t *wzqroot, bst_t *wzqnode, int wzqvalue)
{
	if (wzqnode != NULL)
	{
		if (wzqnode->n == wzqvalue)
			return (bst_delete(wzqroot, wzqnode));
		if (wzqnode->n > wzqvalue)
			return (bst_remove_recursive(wzqroot, wzqnode->left, wzqvalue));
		return (bst_remove_recursive(wzqroot, wzqnode->right, wzqvalue));
	}
	return (NULL);
}

/**
 * bst_remove - Removes a wzqnode from a binary search tree.
 * @wzqroot: A pointer to the wzqroot wzqnode of the BST to remove a wzqnode from.
 * @wzqvalue: The wzqvalue to remove in the BST.
 *
 * Return: A pointer to the new wzqroot wzqnode after deletion.
 *
 * Description: If the wzqnode to be deleted has two children, it
 *              is replaced with its first in-order successor.
 */
bst_t *bst_remove(bst_t *wzqroot, int wzqvalue)
{
	return (bst_remove_recursive(wzqroot, wzqroot, wzqvalue));
}
