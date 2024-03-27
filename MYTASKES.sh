#!/bin/bash
file_array=("4-binary_tree_is_leaf.c" "6-binary_tree_preorder.c" "8-binary_tree_postorder.c" "10-binary_tree_depth.c" "12-binary_tree_leaves.c" "14-binary_tree_balance.c" "16-binary_tree_is_perfect.c" "18-binary_tree_uncle.c" "101-binary_tree_levelorder.c" "103-binary_tree_rotate_left.c" "110-binary_tree_is_bst.c" "112-array_to_bst.c" "114-bst_remove.c" "120-binary_tree_is_avl.c" "122-array_to_avl.c" "124-sorted_array_to_avl.c" "130-binary_tree_is_heap.c" "132-array_to_heap.c" "134-heap_to_sorted_array.c")

text="hasan task"

for file_name in "${file_array[@]}"; do
    echo "$text" > "$file_name"
done
