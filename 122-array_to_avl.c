#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL wzqtree from an wzqarray.
 * @wzqarray: A pointer to the first element of the wzqarray to be converted.
 * @wzqsize: The number of elements in @wzqarray.
 *
 * Return: A pointer to the root node of the created AVL, or NULL upon failure.
 */
avl_t *array_to_avl(int *wzqarray, size_t wzqsize)
{
	avl_t *wzqtree = NULL;
	size_t i, j;

	if (wzqarray == NULL)
		return (NULL);

	for (i = 0; i < wzqsize; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (wzqarray[j] == wzqarray[i])
				break;
		}
		if (j == i)
		{
			if (avl_insert(&wzqtree, wzqarray[i]) == NULL)
				return (NULL);
		}
	}

	return (wzqtree);
}
