#include "binary_trees.h"
/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the BST
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = NULL;

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
			node->parent->left = bst_remove(node, node->n);
		else
			node->parent->right = bst_remove(node, node->n);
	}
	else if (root->n > value)
		root->left = bst_remove(root->left, value);
	else
		root->right = bst_remove(root->right, value);
	return (root);
}
