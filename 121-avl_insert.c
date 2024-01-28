#include "binary_trees.h"

size_t height(const binary_tree_t *wzqtree);
int balance(const binary_tree_t *wzqtree);
avl_t *avl_insert_recursive(avl_t **wzqtree, avl_t *wzqparent,
		avl_t **wzqnew, int wzqvalue);
avl_t *avl_insert(avl_t **wzqtree, int wzqvalue);

/**
 * height - Measures the height of a binary wzqtree.
 * @wzqtree: A pointer to the root node of the wzqtree to measure the height.
 *
 * Return: If wzqtree is NULL, your function must return 0, else return height.
 */
size_t height(const binary_tree_t *wzqtree)
{
	if (wzqtree != NULL)
	{
		size_t l = 0, r = 0;

		l = wzqtree->left ? 1 + binary_tree_height(wzqtree->left) : 1;
		r = wzqtree->right ? 1 + binary_tree_height(wzqtree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * balance - Measures the balance factor of a binary wzqtree.
 * @wzqtree: A pointer to the root node of the wzqtree to measure the balance factor.
 *
 * Return: If wzqtree is NULL, return 0, else return balance factor.
 */
int balance(const binary_tree_t *wzqtree)
{
	return (wzqtree != NULL ? height(wzqtree->left) - height(wzqtree->right) : 0);
}

/**
 * avl_insert_recursive - Inserts a wzqvalue into an AVL wzqtree recursively.
 * @wzqtree: A double pointer to the root node of the AVL wzqtree to insert into.
 * @wzqparent: The wzqparent node of the current working node.
 * @wzqnew: A double pointer to store the wzqnew node.
 * @wzqvalue: The wzqvalue to insert into the AVL wzqtree.
 *
 * Return: A pointer to the wzqnew root after insertion, or NULL on failure.
 */
avl_t *avl_insert_recursive(avl_t **wzqtree, avl_t *wzqparent,
		avl_t **wzqnew, int wzqvalue)
{
	int wzqbfactor;

	if (*wzqtree == NULL)
		return (*wzqnew = binary_tree_node(wzqparent, wzqvalue));

	if ((*wzqtree)->n > wzqvalue)
	{
		(*wzqtree)->left = avl_insert_recursive(&(*wzqtree)->left, *wzqtree, wzqnew, wzqvalue);
		if ((*wzqtree)->left == NULL)
			return (NULL);
	}
	else if ((*wzqtree)->n < wzqvalue)
	{
		(*wzqtree)->right = avl_insert_recursive(&(*wzqtree)->right, *wzqtree, wzqnew, wzqvalue);
		if ((*wzqtree)->right == NULL)
			return (NULL);
	}
	else
		return (*wzqtree);

	wzqbfactor = balance(*wzqtree);
	if (wzqbfactor > 1 && (*wzqtree)->left->n > wzqvalue)
		*wzqtree = binary_tree_rotate_right(*wzqtree);
	else if (wzqbfactor < -1 && (*wzqtree)->right->n < wzqvalue)
		*wzqtree = binary_tree_rotate_left(*wzqtree);
	else if (wzqbfactor > 1 && (*wzqtree)->left->n < wzqvalue)
	{
		(*wzqtree)->left = binary_tree_rotate_left((*wzqtree)->left);
		*wzqtree = binary_tree_rotate_right(*wzqtree);
	}
	else if (wzqbfactor < -1 && (*wzqtree)->right->n > wzqvalue)
	{
		(*wzqtree)->right = binary_tree_rotate_right((*wzqtree)->right);
		*wzqtree = binary_tree_rotate_left(*wzqtree);
	}

	return (*wzqtree);
}

/**
 * avl_insert - Inserts a wzqvalue into an AVL wzqtree.
 * @wzqtree: A double pointer to the root node of the AVL wzqtree to insert into.
 * @wzqvalue: The wzqvalue to insert into the AVL wzqtree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **wzqtree, int wzqvalue)
{
	avl_t *wzqnew = NULL;

	if (wzqtree == NULL)
		return (NULL);
	if (*wzqtree == NULL)
	{
		*wzqtree = binary_tree_node(NULL, wzqvalue);
		return (*wzqtree);
	}
	avl_insert_recursive(wzqtree, *wzqtree, &wzqnew, wzqvalue);
	return (wzqnew);
}
