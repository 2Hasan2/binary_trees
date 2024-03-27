#!/bin/bash

# Check if at least one .c file is present
if ! ls *.c &>/dev/null; then
    echo "No .c files found in the directory."
    exit 1
fi

# Check if a number argument is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <number>"
    exit 1
fi

# # Compile the program excluding files ending with '{number}-main.c'
gcc -Wall -Wextra -Werror $(ls *.c | grep -v "\-main\.c$") "${1}-main.c"  -o "${1}-main"
