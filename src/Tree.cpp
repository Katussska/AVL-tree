//
// Created by katussska on 10/5/23.
//

#include "headers/Tree.h"

// Constructor initializes root pointer to nullptr
Tree::Tree() {
    this->root = nullptr;
}

// Get the height of a node (nullptr has height 0)
int Tree::getNodeHeight(Node *node) {
    if (node == nullptr)
        return 0;

    return node->height;
}

// Check if a node is balanced (the difference in height of left and right subtrees)
int Tree::isBalanced(Node *node) {
    if (node == nullptr)
        return 0;

    // Return the difference in heights between left and right subtrees
    return getNodeHeight(node->left) - getNodeHeight(node->right);
}

// Perform a right rotation on a node
Node *Tree::rightRotation(Node *nodeR) {
    // Save the left child of nodeR as nodeL
    Node *nodeL = nodeR->left;
    // Save the right child of nodeL as temp
    Node *temp = nodeL->right;

    // Redirect the right child of nodeL to nodeR
    nodeL->right = nodeR;
    // Redirect the left child of nodeR to temp
    nodeR->left = temp;

    // Update the height of nodeR to be the maximum height of its left and right subtrees + 1
    nodeR->height = max(getNodeHeight(nodeR->left), getNodeHeight(nodeR->right)) + 1;
    // Update the height of nodeL similarly
    nodeL->height = max(getNodeHeight(nodeL->left), getNodeHeight(nodeL->right)) + 1;

    // Return the new root after rotation, which is nodeL
    return nodeL;
}

// Perform a left rotation on a node
Node *Tree::leftRotation(Node *nodeL) {
    // Save the right child of nodeL as nodeR
    Node *nodeR = nodeL->right;

    // Save the left child of nodeR as temp
    Node *temp = nodeR->left;


    // Redirect the left child of nodeR to nodeL
    nodeR->left = nodeL;
    // Redirect the right child of nodeL to temp
    nodeL->right = temp;

    // Update the height of nodeL to be the maximum height of its left and right subtrees + 1
    nodeL->height = max(getNodeHeight(nodeL->left), getNodeHeight(nodeL->right)) + 1;
    // Update the height of nodeR similarly
    nodeR->height = max(getNodeHeight(nodeR->left), getNodeHeight(nodeR->right)) + 1;

    // Return the new root after rotation, which is nodeR
    return nodeR;
}

// Perform necessary rotations on a node to maintain balance
Node *Tree::rotations(Node *node, int key) {
    // Update the height of the current node
    node->height = 1 + max(getNodeHeight(node->left), getNodeHeight(node->right));

    // Check balance factor for rotations
    int balance = isBalanced(node);

    // LL rotation
    // If balance > 1 and the problem is in the left subtree and further to the left
    if (balance > 1 && key < node->left->key)
        return rightRotation(node);

    // RR rotation
    // If balance < -1 and the problem is in the right subtree and further to the right
    if (balance < -1 && key > node->right->key)
        return leftRotation(node);

    // LR rotation
    // If balance > 1 and the problem is in the left subtree, but further to the right
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }

    // RL rotation
    // If balance < -1 and the problem is in the right subtree, but further to the left
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }

    // If no rotations are needed, return the current node
    return node;
}

// Insert a new node with a key into the tree
Node *Tree::insert(Node *node, int key) {
    // If the node is nullptr, create a new node with the given key
    if (node == nullptr)
        return new Node(key);

    // If the key is less than the current node's key, insert to the left
    if (key < node->key) //hodnota mensi, prida se doleva
        node->left = insert(node->left, key);
        // If the key is greater, insert to the right
    else if (key > node->key) // hodnota vetsi, prida se doprava
        node->right = insert(node->right, key);
        // If the key is equal, it's a duplicate and no insertion is done
    else
        return node;

    // Perform rotations after insertion
    return rotations(node, key);
}

// Search for a key in the tree and print information about the node
void Tree::search(Node *root, int key) {
    Node *current = root; // Initialize a pointer to the root of the tree
    Node *parent = nullptr; // Initialize a pointer to track the parent of the current node

    // Loop until the current node is null or the key is found
    while (current != nullptr && current->key != key) {
        parent = current; // Update parent to the current node

        // If the key is less than the current node's key, move to the left child
        if (key < current->key)
            current = current->left;
        else
            current = current->right; // Otherwise, move to the right child
    }

    // If the current node is null, the key was not found
    if (current == nullptr) {
        cout << "Value " << key << " was not found" << endl;
        return;
    }

    // Print information about the found node
    cout << key << "'s height in tree is " << current->height << endl;

    // Print parent information (or root if no parent)
    if (parent != nullptr)
        cout << current->key << "'s parent is " << parent->key << endl;
    else
        cout << current->key << " node is the root" << endl;

    // Print information about the left child (if exists)
    if (current->left != nullptr)
        cout << current->key << "'s left node is " << current->left->key << endl;
    else
        cout << current->key << " does not have left node " << endl;

    // Print information about the right child (if exists)
    if (current->right != nullptr)
        cout << current->key << "'s right node is " << current->right->key << endl;
    else
        cout << current->key << " does not have right node " << endl;
}

// Find the node with the minimum value in a subtree
Node *Tree::minValueNode(Node *node) {
    Node *current = node;

    // Traverse as far left as possible to find the minimum value
    while (current && current->left != nullptr)
        current = current->left;

    return current;
}

// Delete a node with a specific key from the tree
Node *Tree::deleteNode(Node *node, int key) {
    // If the node is null, return it (no deletion needed)
    if (node == nullptr)
        return node;

    // If the key is less than the current node's key, go left
    if (key < node->key)
        node->left = deleteNode(node->left, key);
        // If the key is greater, go right
    else if (key > node->key)
        node->right = deleteNode(node->right, key);
    else {
        // Node with matching key found

        // If the node has at most one child
        if ((node->left == nullptr) || (node->right == nullptr)) {
            Node *temp = node->left ? node->left : node->right;

            // If temp is null, assign it to node and set node to null
            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else
                *node = *temp; // Copy content of temp to node

            delete temp; // Delete temp (which contained the node to be deleted)
        } else {
            // Node has two children

            // Find the minimum value in the right subtree
            Node *temp = minValueNode(node->right);

            // Copy the key of the minimum value node to the current node
            node->key = temp->key;

            // Delete the minimum value node from the right subtree
            node->right = deleteNode(node->right, temp->key);
        }
    }

    // If node is null, return it (no rotations needed)
    if (node == nullptr)
        return node;

    // Perform rotations after deletion
    return rotations(node, key);
}

// Print the tree structure with proper indentation
void Tree::printTree(Node *node, int space) {
    // If the node is null, return (base case for recursion)
    if (node == nullptr)
        return;

    const int distance = 5; // The distance between nodes from left to right and space from top to bottom
    space += distance; // Increase the indentation for child nodes

    // Recursively print the right subtree with increased indentation
    if (node->right != nullptr)
        printTree(node->right, space);

    cout << endl; // Move to a new line for better visual representation
    for (int i = distance; i < space; i++)
        cout << " "; // Print spaces for indentation
    cout << node->key << endl; // Print the key of the current node

    // Recursively print the left subtree with increased indentation
    if (node->left != nullptr)
        printTree(node->left, space);
}
