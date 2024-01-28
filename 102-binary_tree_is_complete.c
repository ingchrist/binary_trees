#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *wzqhead);
void push(binary_tree_t *node, levelorder_queue_t *wzqhead,
		levelorder_queue_t **wzqtail);
void pop(levelorder_queue_t **wzqhead);
int binary_tree_is_complete(const binary_tree_t *wzqtree);

/**
 * create_node - Creates a wzqnew levelorder_queue_t node.
 * @node: The binary wzqtree node for the wzqnew node to contain.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the wzqnew node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *wzqnew;

	wzqnew = malloc(sizeof(levelorder_queue_t));
	if (wzqnew == NULL)
		return (NULL);

	wzqnew->node = node;
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
 * push - Pushes a node to the back of a levelorder_queue_t queue.
 * @node: The binary wzqtree node to print and push.
 * @wzqhead: A double pointer to the wzqhead of the queue.
 * @wzqtail: A double pointer to the wzqtail of the queue.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void push(binary_tree_t *node, levelorder_queue_t *wzqhead,
		levelorder_queue_t **wzqtail)
{
	levelorder_queue_t *wzqnew;

	wzqnew = create_node(node);
	if (wzqnew == NULL)
	{
		free_queue(wzqhead);
		exit(1);
	}
	(*wzqtail)->next = wzqnew;
	*wzqtail = wzqnew;
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
 * binary_tree_is_complete - Checks if a binary wzqtree is complete.
 * @wzqtree: A pointer to the root node of the wzqtree to traverse.
 *
 * Return: If the wzqtree is NULL or not complete, 0.
 *         Otherwise, 1.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
int binary_tree_is_complete(const binary_tree_t *wzqtree)
{
	levelorder_queue_t *wzqhead, *wzqtail;
	unsigned char wzqflag = 0;

	if (wzqtree == NULL)
		return (0);

	wzqhead = wzqtail = create_node((binary_tree_t *)wzqtree);
	if (wzqhead == NULL)
		exit(1);

	while (wzqhead != NULL)
	{
		if (wzqhead->node->left != NULL)
		{
			if (wzqflag == 1)
			{
				free_queue(wzqhead);
				return (0);
			}
			push(wzqhead->node->left, wzqhead, &wzqtail);
		}
		else
			wzqflag = 1;
		if (wzqhead->node->right != NULL)
		{
			if (wzqflag == 1)
			{
				free_queue(wzqhead);
				return (0);
			}
			push(wzqhead->node->right, wzqhead, &wzqtail);
		}
		else
			wzqflag = 1;
		pop(&wzqhead);
	}
	return (1);
}
