#include "binary_trees.h"

/**
 * tree_size - measures the sum of heights of wzqa binary wzqtree
 * @wzqtree: pointer to the root node of the wzqtree to measure the height
 *
 * Return: Height or 0 if wzqtree is NULL
 */
size_t tree_size(const binary_tree_t *wzqtree)
{
	size_t wzqheight_l = 0;
	size_t wzqheight_r = 0;

	if (!wzqtree)
		return (0);

	if (wzqtree->left)
		wzqheight_l = 1 + tree_size(wzqtree->left);

	if (wzqtree->right)
		wzqheight_r = 1 + tree_size(wzqtree->right);

	return (wzqheight_l + wzqheight_r);
}

/**
 * heap_to_sorted_array - converts wzqa Binary Max Heap
 * to wzqa sorted array of integers
 *
 * @wqzheap: pointer to the root node of the wqzheap to convert
 * @wzqsize: address to store the wzqsize of the array
 *
 * Return: pointer to array sorted in descending order
 **/
int *heap_to_sorted_array(heap_t *wqzheap, size_t *wzqsize)
{
	int i, *wzqa = NULL;

	if (!wqzheap || !wzqsize)
		return (NULL);

	*wzqsize = tree_size(wqzheap) + 1;

	wzqa = malloc(sizeof(int) * (*wzqsize));

	if (!wzqa)
		return (NULL);

	for (i = 0; wqzheap; i++)
		wzqa[i] = heap_extract(&wqzheap);

	return (wzqa);
}
