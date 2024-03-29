#include "binary_trees.h"
/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (!array || size == 0)
		return (NULL);

	root = sorted_array_to_avl_rec(array, 0, size - 1, NULL);
	return (root);
}

/**
 * sorted_array_to_avl_rec - recursively builds an AVL tree from a sorted array
 * @array: pointer to the first element of the array to be converted
 * @start: index of the first element in the current subarray
 * @end: index of the last element in the current subarray
 * @parent: pointer to the parent node of the current node
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl_rec(int *array, size_t start, size_t end, avl_t *parent)
{
	avl_t *node = NULL;
	size_t mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	node = binary_tree_node(parent, array[mid]);
	if (!node)
		return (NULL);

	if (mid != start)
		node->left = sorted_array_to_avl_rec(array, start, mid - 1, node);
	if (mid != end)
		node->right = sorted_array_to_avl_rec(array, mid + 1, end, node);

	return (node);
}
