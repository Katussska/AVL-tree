# AVL Tree Implementation in C++

C++ implementation of an AVL Tree, a self-balancing binary search tree.
The code includes the following functions: insert, delete, search, and print.
It is fully functional and well-commented.

## Table of Contents

- [Introduction](#introduction)
- [Functions](#functions)
    - [Insert](#insert)
    - [Delete](#delete)
    - [Search](#search)
    - [Print](#print)

## Introduction

An AVL Tree is a self-balancing binary search tree where the height of the two child subtrees of every node differs by
at most one. This implementation provides efficient methods for inserting, deleting, searching, and printing elements
within the tree.

## Functions

### Insert

The `insert` function allows you to add a new value to the AVL Tree while maintaining its balanced property.

```cpp
// Function
Node *insert(Node *node, int key);

// Example
AVLTree.insert(AVLTree.root, 19);
```

### Delete

The `deleteNode` function removes a value from the AVL Tree, if it exists. This operation also ensures that the tree
remains balanced. If the value is found and removed, the tree's structure is adjusted accordingly.

```cpp
// Function
Node *deleteNode(Node *root, int key);

// Example
AVLTree.deleteNode(AVLTree.root, 32);
```

### Search

The `search` function finds a value in the AVL Tree and prints its current location, parent, and children (if any).
If the value is at the root, it will indicate that.

```cpp
// Function
static void search(Node *root, int key);

// Example
Tree::search(AVLTree.root, 32);
```

#### Output

![search.png](images%2Fsearch.png)

### Print

The `printTree` function outputs the elements of the AVL Tree in sorted order.

```cpp
// Function
void printTree(Node *root, int space);

// Example
AVLTree.printTree(AVLTree.root, 0);
```

#### Output

![print.png](images%2Fprint.png)