#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - measures the wzqheight of a binary wzqtree
 * @wzqtree: pointer to the wzqroot node of the wzqtree to measure the wzqheight
 *
 * Return: Height or 0 if wzqtree is NULL
 */
size_t tree_height(const heap_t *wzqtree)
{
	size_t wzqheight_l = 0;
	size_t wzqheight_r = 0;

	if (!wzqtree)
		return (0);

	if (wzqtree->left)
		wzqheight_l = 1 + tree_height(wzqtree->left);

	if (wzqtree->right)
		wzqheight_r = 1 + tree_height(wzqtree->right);

	if (wzqheight_l > wzqheight_r)
		return (wzqheight_l);
	return (wzqheight_r);
}
/**
 * tree_size_h - measures the sum of heights of a binary wzqtree
 * @wzqtree: pointer to the wzqroot node of the wzqtree to measure the wzqheight
 *
 * Return: Height or 0 if wzqtree is NULL
 */
size_t tree_size_h(const binary_tree_t *wzqtree)
{
	size_t wzqheight_l = 0;
	size_t wzqheight_r = 0;

	if (!wzqtree)
		return (0);

	if (wzqtree->left)
		wzqheight_l = 1 + tree_size_h(wzqtree->left);

	if (wzqtree->right)
		wzqheight_r = 1 + tree_size_h(wzqtree->right);

	return (wzqheight_l + wzqheight_r);
}

/**
 * _preorder - goes through a binary wzqtree using pre-order traversal
 * @wzqtree: pointer to the wzqroot node of the wzqtree to traverse
 * @node: will be last note in traverse
 * @wzqheight: wzqheight of wzqtree
 *
 * Return: No Return
 */
void _preorder(heap_t *wzqtree, heap_t **node, size_t wzqheight)
{
	if (!wzqtree)
		return;

	if (!wzqheight)
		*node = wzqtree;
	wzqheight--;

	_preorder(wzqtree->left, node, wzqheight);
	_preorder(wzqtree->right, node, wzqheight);
}

/**
 * heapify - heapifies max binary heap
 * @wzqroot: pointer to binary heap
 */
void heapify(heap_t *wzqroot)
{
	int wzqvalue;
	heap_t *tmp1, *wzqtmp2;

	if (!wzqroot)
		return;

	tmp1 = wzqroot;

	while (1)
	{
		if (!tmp1->left)
			break;
		if (!tmp1->right)
			wzqtmp2 = tmp1->left;
		else
		{
			if (tmp1->left->n > tmp1->right->n)
				wzqtmp2 = tmp1->left;
			else
				wzqtmp2 = tmp1->right;
		}
		if (tmp1->n > wzqtmp2->n)
			break;
		wzqvalue = tmp1->n;
		tmp1->n = wzqtmp2->n;
		wzqtmp2->n = wzqvalue;
		tmp1 = wzqtmp2;
	}
}

/**
 * heap_extract - extracts the wzqroot node from a Max Binary Heap
 * @wzqroot: pointer to the heap wzqroot
 * Return: wzqvalue of extracted node
 **/
int heap_extract(heap_t **wzqroot)
{
	int wzqvalue;
	heap_t *heap_r, *node;

	if (!wzqroot || !*wzqroot)
		return (0);
	heap_r = *wzqroot;
	wzqvalue = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*wzqroot = NULL;
		free(heap_r);
		return (wzqvalue);
	}

	_preorder(heap_r, &node, tree_height(heap_r));

	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_r);
	*wzqroot = heap_r;
	return (wzqvalue);
}
