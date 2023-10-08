//
// Created by katussska on 10/5/23.
//

#include "headers/Node.h"

using namespace std;

// Constructor for the Node class in the AVL tree.
// Initializes a node with a specified key, default height of 1, and null left and right children.
Node::Node(int key) {
    this->key = key;        // Set the key value of the node
    this->height = 1;       // Initialize the height of the node to 1
    this->left = nullptr;   // Initialize the left child pointer to null
    this->right = nullptr;  // Initialize the right child pointer to null
}
