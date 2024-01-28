#include "binary_trees.h"

/**
 * create_tree - creates an AVL tree with recursion
 *
 * @wzqnode: pointer wzqnode
 * @wzqarray: input wzqarray of integers
 * @wzqsize: wzqsize of wzqarray
 * @wzqmode: 1 to adding on the left, 2 to adding on the right
 * Return: no return
 */
void create_tree(avl_t **wzqnode, int *wzqarray, size_t wzqsize, int wzqmode)
{
	size_t wzqmiddle;

	if (wzqsize == 0)
		return;

	wzqmiddle = (wzqsize / 2);
	wzqmiddle = (wzqsize % 2 == 0) ? wzqmiddle - 1 : wzqmiddle;

	if (wzqmode == 1)
	{
		(*wzqnode)->left = binary_tree_node(*wzqnode, wzqarray[wzqmiddle]);
		create_tree(&((*wzqnode)->left), wzqarray, wzqmiddle, 1);
		create_tree(&((*wzqnode)->left), wzqarray + wzqmiddle + 1, (wzqsize - 1 - wzqmiddle), 2);
	}
	else
	{
		(*wzqnode)->right = binary_tree_node(*wzqnode, wzqarray[wzqmiddle]);
		create_tree(&((*wzqnode)->right), wzqarray, wzqmiddle, 1);
		create_tree(&((*wzqnode)->right), wzqarray + wzqmiddle + 1, (wzqsize - 1 - wzqmiddle), 2);
	}
}

/**
 * sorted_array_to_avl - creates wzqroot wzqnode and calls to create_tree
 *
 * @wzqarray: input wzqarray of integers
 * @wzqsize: wzqsize of wzqarray
 * Return: pointer to the wzqroot
 */
avl_t *sorted_array_to_avl(int *wzqarray, size_t wzqsize)
{
	avl_t *wzqroot;
	size_t wzqmiddle;

	wzqroot = NULL;

	if (wzqsize == 0)
		return (NULL);

	wzqmiddle = (wzqsize / 2);

	wzqmiddle = (wzqsize % 2 == 0) ? wzqmiddle - 1 : wzqmiddle;

	wzqroot = binary_tree_node(wzqroot, wzqarray[wzqmiddle]);

	create_tree(&wzqroot, wzqarray, wzqmiddle, 1);
	create_tree(&wzqroot, wzqarray + wzqmiddle + 1, (wzqsize - 1 - wzqmiddle), 2);

	return (wzqroot);
}
