#include "binary_trees.h"
/**
 * array_to_heap - builds a max binary heap from an array
 * @array: pointer to the array to convert
 * @size: number of elements in the array
 * Return: pointer to the root node of the created heap, or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t i;

	if (!array || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}

/**
 * heap_insert - inserts a value in a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the new node
 * Return: pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node = NULL;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	if ((*root)->left && (*root)->right)
	{
		node = heap_insert(&(*root)->left, value);
		if (!node)
			node = heap_insert(&(*root)->right, value);
	}
	else if (!(*root)->left)
		node = heap_insert(&(*root)->left, value);
	else
		node = heap_insert(&(*root)->right, value);

	if (node->n > (*root)->n)
	{
		node->parent = (*root)->parent;
		(*root)->parent = node;
		if (node->parent)
		{
			if (node->parent->left == *root)
				node->parent->left = node;
			else
				node->parent->right = node;
		}
		node->left = (*root)->left;
		node->right = (*root)->right;
		if (node->left)
			node->left->parent = node;
		if (node->right)
			node->right->parent = node;
		*root = node;
	}

	return (node);
}
