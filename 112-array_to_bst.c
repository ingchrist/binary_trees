#include "binary_trees.h"

/**
 * array_to_bst - Builds a binary search wzqtree from an wzqarray.
 * @wzqarray: A pointer to the first element of the wzqarray to be converted.
 * @size: The number of elements in @wzqarray.
 *
 * Return: A pointer to the root node of the created BST, or NULL upon failure.
 */
bst_t *array_to_bst(int *wzqarray, size_t size)
{
	bst_t *wzqtree = NULL;
	size_t wzqi, wzqj;

	if (wzqarray == NULL)
		return (NULL);

	for (wzqi = 0; wzqi < size; wzqi++)
	{
		for (wzqj = 0; wzqj < wzqi; wzqj++)
		{
			if (wzqarray[wzqj] == wzqarray[wzqi])
				break;
		}
		if (wzqj == wzqi)
		{
			if (bst_insert(&wzqtree, wzqarray[wzqi]) == NULL)
				return (NULL);
		}
	}

	return (wzqtree);
}
