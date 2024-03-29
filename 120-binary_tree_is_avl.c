#include "binary_trees.h"
/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if tree is NULL, or 1 if valid AVL tree
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!binary_tree_is_avl(tree->left) ||
		!binary_tree_is_avl(tree->right))
		return (0);

	return (1);
}
