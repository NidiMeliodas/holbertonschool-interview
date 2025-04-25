# Heap Insert

This project focuses on implementing a function to insert values into a **Max Binary Heap**, a specialized binary tree where each parent node is greater than or equal to its children.

---

## Requirements

### General

- Allowed editors: `vi`, `vim`, `emacs`
- OS: Ubuntu 14.04 LTS
- Compiler: `gcc 4.8.4`
- Compilation flags:
-Wall -Werror -Wextra -pedantic

- All source files must:
- End with a new line
- Use **Betty style** (`betty-style.pl` and `betty-doc.pl`)
- Contain no global variables
- Have no more than 5 functions per file
- Use only the standard library
- A `README.md` file at the root of the project is mandatory
- All function prototypes must be included in the `binary_trees.h` header file
- Header files must be include guarded
- Example `main.c` files can be used for testing but should not be pushed

---

## Data Structures

### Binary Tree Node

````c
/**
* struct binary_tree_s - Binary tree node
*
* @n: Integer stored in the node
* @parent: Pointer to the parent node
* @left: Pointer to the left child node
* @right: Pointer to the right child node
*/
struct binary_tree_s
{
  int n;
  struct binary_tree_s *parent;
  struct binary_tree_s *left;
  struct binary_tree_s *right;
};
 # Max Binary Heap Alias
 typedef struct binary_tree_s heap_t;

Compilation
Use the following command to compile:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o heap_insert

File Structure
.
├── binary_trees.h        # Header file with data structures and function prototypes
├── 0-heap_insert.c       # Function to insert into a Max Binary Heap
├── main.c                # (Optional) Test file - do not push
├── README.md             # Project documentation
└── other_helper.c        # (Optional) Helper functions

Objectives
Implement heap_insert() to insert values into a Max Binary Heap

Maintain correct tree structure and heap property after insertion

Reorganize the heap by swapping nodes as needed (heapify-up)

