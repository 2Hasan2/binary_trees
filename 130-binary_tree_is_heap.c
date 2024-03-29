#include "binary_trees.h"
/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if tree is NULL, or 1 if valid Max Binary Heap
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!binary_tree_is_heap(tree->left) ||
		!binary_tree_is_heap(tree->right))
		return (0);

	return (1);
}
