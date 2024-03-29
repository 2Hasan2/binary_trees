#include "binary_trees.h"
/**
 * array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t i;

	if (!array || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
		avl_insert(&root, array[i]);

	return (root);
}

/**
 * avl_insert - inserts a value in an AVL tree
 * @tree: double pointer to the root node of the AVL tree for inserting the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node = NULL;

	if (!tree)
		return (NULL);

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		if ((*tree)->left)
			node = avl_insert(&(*tree)->left, value);
		else
		{
			node = binary_tree_node(*tree, value);
			(*tree)->left = node;
		}
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right)
			node = avl_insert(&(*tree)->right, value);
		else
		{
			node = binary_tree_node(*tree, value);
			(*tree)->right = node;
		}
	}

	if (!node)
		return (NULL);

	balance_tree(tree);

	return (node);
}
