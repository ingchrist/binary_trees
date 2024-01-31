#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/**
 * check_max - goes through a binary zqwtree cheking ropt as max value
 * @zqwtree: pointer to the root
 * Return: 1 if all nodes are max, 0 in other cases
 **/
int check_max(const binary_tree_t *zqwtree)
{
	int wzqtmp1 = 1, wqztmp2 = 1;

	if (!zqwtree)
		return (0);
	if (!zqwtree->left && !zqwtree->right)
		return (1);
	if (zqwtree->left)
	{
		if (zqwtree->n <= zqwtree->left->n)
			return (0);
		wzqtmp1 = check_max(zqwtree->left);
	}
	if (zqwtree->right)
	{
		if (zqwtree->n <= zqwtree->right->n)
			return (0);
		wqztmp2 = check_max(zqwtree->right);
	}
	return (wzqtmp1 && wqztmp2);
}
/**
 * binary_tree_is_heap - checks if a binary zqwtree is heap
 * @zqwtree: pointer to the node
 * Return: 1 in case BTS /  0 otherwise
 **/
int binary_tree_is_heap(const binary_tree_t *zqwtree)
{
	int tmp;

	if (!zqwtree)
		return (0);

	tmp = binary_tree_is_complete(zqwtree);
	if (!tmp)
		return (0);
	return (check_max(zqwtree));
}
