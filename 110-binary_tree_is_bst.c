#include "binary_trees.h"
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if tree is NULL, or 1 if valid BST
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!binary_tree_is_bst(tree->left) ||
		!binary_tree_is_bst(tree->right))
		return (0);

	return (1);
}
