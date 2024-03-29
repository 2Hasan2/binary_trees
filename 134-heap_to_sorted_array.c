#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
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

/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted array
 * @heap: pointer to the root node of the Heap
 * @size: address to store the size of the array
 * Return: pointer to the newly created sorted array, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array = NULL;
	size_t i = 0;

	if (!heap || !size)
		return (NULL);

	*size = binary_tree_size(heap);
	array = malloc(sizeof(int) * *size);
	if (!array)
		return (NULL);

	heap_to_array(heap, array, &i);

	return (array);
}
