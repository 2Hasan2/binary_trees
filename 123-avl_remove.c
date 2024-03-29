#include "binary_trees.h"
/**
 * avl_remove - removes a node from an AVL tree
 * @root: pointer to the root node of the tree
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node = NULL;

	if (!root)
		return (NULL);

	if (root->n == value)
	{
		if (!root->left && !root->right)
		{
			free(root);
			return (NULL);
		}
		if (!root->left)
		{
			node = root->right;
			node->parent = root->parent;
			free(root);
			return (node);
		}
		if (!root->right)
		{
			node = root->left;
			node->parent = root->parent;
			free(root);
			return (node);
		}
		node = root->right;
		while (node->left)
			node = node->left;
		root->n = node->n;
		if (node->parent->left == node)
			node->parent->left = avl_remove(node, node->n);
		else
			node->parent->right = avl_remove(node, node->n);
	}
	else if (root->n > value)
		root->left = avl_remove(root->left, value);
	else
		root->right = avl_remove(root->right, value);
	return (root);
}
