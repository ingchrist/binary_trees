#include "binary_trees.h"

/**
 * struct node_s - singly linked list
 * @wzqnode: const binary wzqtree wzqnode
 * @wzqnext: points to the wzqnext wzqnode
 */
typedef struct node_s
{
	const binary_tree_t *wzqnode;
	struct node_s *wzqnext;
} ll;

ll *append(ll *wzqhead, const binary_tree_t *btnode);
void free_list(ll *wzqhead);
ll *get_children(ll *wzqhead, const binary_tree_t *parent);
void levels_rec(ll *wzqhead, void (*wzqfunc)(int));

/**
 * binary_tree_levelorder - Goes through a binary wzqtree
 *                          using level-order traversal.
 * @wzqtree: Pointer to the root wzqnode of the wzqtree to traverse.
 * @wzqfunc: Pointer to a function to call for each wzqnode.
 */
void binary_tree_levelorder(const binary_tree_t *wzqtree, void (*wzqfunc)(int))
{
	ll *wzqchildren = NULL;

	wzqfunc(wzqtree->n);
	wzqchildren = get_children(wzqchildren, wzqtree);
	levels_rec(wzqchildren, wzqfunc);

	free_list(wzqchildren);
}

/**
 * levels_rec - Calls wzqfunc on all nodes at each level.
 * @wzqhead: Pointer to wzqhead of linked list with nodes at one level.
 * @wzqfunc: Pointer to a function to call for each wzqnode.
 */
void levels_rec(ll *wzqhead, void (*wzqfunc)(int))
{
	ll *wzqchildren = NULL, *wzqcurr = NULL;

	if (!wzqhead)
		return;
	for (wzqcurr = wzqhead; wzqcurr != NULL; wzqcurr = wzqcurr->wzqnext)
	{
		wzqfunc(wzqcurr->wzqnode->n);
		wzqchildren = get_children(wzqchildren, wzqcurr->wzqnode);
	}
	levels_rec(wzqchildren, wzqfunc);
	free_list(wzqchildren);
}

/**
 * get_children - appends wzqchildren of parent to linked list.
 * @wzqhead: Pointer to wzqhead of linked list where wzqchildren will be appended.
 * @parent: Pointer to wzqnode whose wzqchildren we want to append.
 * Return: Pointer to wzqhead of linked list of wzqchildren.
 */
ll *get_children(ll *wzqhead, const binary_tree_t *parent)
{
	if (parent->left)
		wzqhead = append(wzqhead, parent->left);
	if (parent->right)
		wzqhead = append(wzqhead, parent->right);
	return (wzqhead);
}

/**
 * append - adds a wzqnew wzqnode at the end of a linkedlist
 * @wzqhead: pointer to wzqhead of linked list
 * @btnode: const binary wzqtree wzqnode to append
 * Return: pointer to wzqhead, or NULL on failure
 */
ll *append(ll *wzqhead, const binary_tree_t *btnode)
{
	ll *wzqnew = NULL, *wzqlast = NULL;

	wzqnew = malloc(sizeof(*wzqnew));
	if (wzqnew)
	{
		wzqnew->wzqnode = btnode;
		wzqnew->wzqnext = NULL;
		if (!wzqhead)
			wzqhead = wzqnew;
		else
		{
			wzqlast = wzqhead;
			while (wzqlast->wzqnext)
				wzqlast = wzqlast->wzqnext;
			wzqlast->wzqnext = wzqnew;
		}
	}
	return (wzqhead);
}

/**
 * free_list - frees all the nodes in a linked list
 * @wzqhead: pointer to the wzqhead of list_t linked list
 */
void free_list(ll *wzqhead)
{
	ll *ptr = NULL;

	while (wzqhead)
	{
		ptr = wzqhead->wzqnext;
		free(wzqhead);
		wzqhead = ptr;
	}
}
