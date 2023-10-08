//
// Created by katussska on 10/5/23.
//

#ifndef AVL_TREE_TREE_H
#define AVL_TREE_TREE_H

#include "Node.h"

// The Tree class represents an AVL (Adelson-Velsky and Landis) Tree, a self-balancing binary search tree.
// It contains methods for insertion, deletion, searching, and printing of nodes.
// The tree is maintained in a balanced state, ensuring efficient search, insert, and delete operations.
class Tree {
public:
    Node *root; // Pointer to the root node of the tree

    Tree(); // Constructor

    // Static methods for height and balancing
    static int getNodeHeight(Node *node);

    static int isBalanced(Node *node);

    // Methods for rotations
    static Node *rightRotation(Node *node);

    static Node *leftRotation(Node *node);

    // Method for performing rotations based on key and balance factors
    static Node *rotations(Node *node, int key);

    // Method for inserting a node with a specified key
    Node *insert(Node *node, int key);

    // Method for finding the node with the minimum value in a subtree
    static Node *minValueNode(Node *node);

    // Method for deleting a node with a specific key
    Node *deleteNode(Node *root, int key);

    // Method for searching and printing information about a node and its children
    static void search(Node *root, int key);

    // Method for printing the tree structure with proper indentation
    void printTree(Node *root, int space);
};

#endif //AVL_TREE_TREE_H
