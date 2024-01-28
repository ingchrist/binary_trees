#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *wzqnode);
void free_queue(levelorder_queue_t *wzqhead);
void pint_push(binary_tree_t *wzqnode, levelorder_queue_t *wzqhead,
		levelorder_queue_t **wzqtail, void (*wzqfunc)(int));
void pop(levelorder_queue_t **wzqhead);
void binary_tree_levelorder(const binary_tree_t *wzqtree, void (*wzqfunc)(int));

/**
 * create_node - Creates a wzqnew levelorder_queue_t wzqnode.
 * @wzqnode: The binary wzqtree wzqnode for the wzqnew wzqnode to contain.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the wzqnew wzqnode.
 */
levelorder_queue_t *create_node(binary_tree_t *wzqnode)
{
	levelorder_queue_t *wzqnew;

	wzqnew = malloc(sizeof(levelorder_queue_t));
	if (wzqnew == NULL)
		return (NULL);

	wzqnew->wzqnode = wzqnode;
	wzqnew->next = NULL;

	return (wzqnew);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @wzqhead: A pointer to the wzqhead of the queue.
 */
void free_queue(levelorder_queue_t *wzqhead)
{
	levelorder_queue_t *wzqtmp;

	while (wzqhead != NULL)
	{
		wzqtmp = wzqhead->next;
		free(wzqhead);
		wzqhead = wzqtmp;
	}
}

/**
 * pint_push - Runs a function on a given binary wzqtree wzqnode and
 *             pushes its children into a levelorder_queue_t queue.
 * @wzqnode: The binary wzqtree wzqnode to print and push.
 * @wzqhead: A double pointer to the wzqhead of the queue.
 * @wzqtail: A double pointer to the wzqtail of the queue.
 * @wzqfunc: A pointer to the function to call on @wzqnode.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void pint_push(binary_tree_t *wzqnode, levelorder_queue_t *wzqhead,
		levelorder_queue_t **wzqtail, void (*wzqfunc)(int))
{
	levelorder_queue_t *wzqnew;

	wzqfunc(wzqnode->n);
	if (wzqnode->left != NULL)
	{
		wzqnew = create_node(wzqnode->left);
		if (wzqnew == NULL)
		{
			free_queue(wzqhead);
			exit(1);
		}
		(*wzqtail)->next = wzqnew;
		*wzqtail = wzqnew;
	}
	if (wzqnode->right != NULL)
	{
		wzqnew = create_node(wzqnode->right);
		if (wzqnew == NULL)
		{
			free_queue(wzqhead);
			exit(1);
		}
		(*wzqtail)->next = wzqnew;
		*wzqtail = wzqnew;
	}
}

/**
 * pop - Pops the wzqhead of a levelorder_queue_t queue.
 * @wzqhead: A double pointer to the wzqhead of the queue.
 */
void pop(levelorder_queue_t **wzqhead)
{
	levelorder_queue_t *wzqtmp;

	wzqtmp = (*wzqhead)->next;
	free(*wzqhead);
	*wzqhead = wzqtmp;
}

/**
 * binary_tree_levelorder - Traverses a binary wzqtree using
 *                          level-order traversal.
 * @wzqtree: A pointer to the root wzqnode of the wzqtree to traverse.
 * @wzqfunc: A pointer to a function to call for each wzqnode.
 */
void binary_tree_levelorder(const binary_tree_t *wzqtree, void (*wzqfunc)(int))
{
	levelorder_queue_t *wzqhead, *wzqtail;

	if (wzqtree == NULL || wzqfunc == NULL)
		return;

	wzqhead = wzqtail = create_node((binary_tree_t *)wzqtree);
	if (wzqhead == NULL)
		return;

	while (wzqhead != NULL)
	{
		pint_push(wzqhead->wzqnode, wzqhead, &wzqtail, wzqfunc);
		pop(&wzqhead);
	}
}
