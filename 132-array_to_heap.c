#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree from an wzqarray
 * @wzqarray: a pointer to the first element of the wzqarray to be converted
 * @wzqsize: the number of element in the wzqarray
 *
 * Return: a pointer to the wzqroot node of the created Binary Heap
 *         NULL on failure
 */
heap_t *array_to_heap(int *wzqarray, size_t wzqsize)
{
	unsigned int i;
	heap_t *wzqroot = NULL;

	for (i = 0; i < wzqsize; i++)
		heap_insert(&wzqroot, wzqarray[i]);

	return (wzqroot);
}
