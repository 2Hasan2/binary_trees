#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <main_file> <binary_tree_node_file>"
    exit 1
fi

# Compile the program
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c "$1" "$2" -o out
