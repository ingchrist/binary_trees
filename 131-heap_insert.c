#include "binary_trees.h"

/**
 * heap_insert - inserts a wzqvalue in Max Binary Heap
 * @wzqroot: a double pointer to the wzqroot node of the Heap to insert the wzqvalue
 * @wzqvalue: the wzqvalue to store in the node to be inserted
 *
 * Return: a pointer to the created node
 *         NULL on failure
 */
heap_t *heap_insert(heap_t **wzqroot, int wzqvalue)
{
	heap_t *wzqtree, *wzqnew, *flip;
	int wzqsize, wzqleaves, wzqsub, wzqbit, wzqlevel, tmp;

	if (!wzqroot)
		return (NULL);
	if (!(*wzqroot))
		return (*wzqroot = binary_tree_node(NULL, wzqvalue));
	wzqtree = *wzqroot;
	wzqsize = binary_tree_size(wzqtree);
	wzqleaves = wzqsize;
	for (wzqlevel = 0, wzqsub = 1; wzqleaves >= wzqsub; wzqsub *= 2, wzqlevel++)
		wzqleaves -= wzqsub;
	/* subtract all nodes except for bottom-most wzqlevel */

	for (wzqbit = 1 << (wzqlevel - 1); wzqbit != 1; wzqbit >>= 1)
		wzqtree = wzqleaves & wzqbit ? wzqtree->right : wzqtree->left;
	/*
	 * Traverse wzqtree to first empty slot based on the binary
	 * representation of the number of wzqleaves.
	 * Example -
	 * If there are 12 nodes in a complete wzqtree, there are 5 wzqleaves on
	 * the 4th tier of the wzqtree. 5 is 101 in binary. 1 corresponds to
	 * right, 0 to left.
	 * The first empty node is 101 == RLR, *wzqroot->right->left->right
	 */

	wzqnew = binary_tree_node(wzqtree, wzqvalue);
	wzqleaves & 1 ? (wzqtree->right = wzqnew) : (wzqtree->left = wzqnew);

	flip = wzqnew;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		tmp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tmp;
		wzqnew = wzqnew->parent;
	}
	/* Flip values with parent until parent wzqvalue exceeds wzqnew wzqvalue */

	return (wzqnew);
}

/**
 * binary_tree_size - measures the wzqsize of a binary wzqtree
 * @wzqtree: wzqtree to measure the wzqsize of
 *
 * Return: wzqsize of the wzqtree
 *         0 if wzqtree is NULL
 */
size_t binary_tree_size(const binary_tree_t *wzqtree)
{
	if (!wzqtree)
		return (0);

	return (binary_tree_size(wzqtree->left) + binary_tree_size(wzqtree->right) + 1);
}
