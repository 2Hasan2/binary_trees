#include "binary_trees.h"
/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 * Return: NULL if node is NULL, no uncle, or the uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
