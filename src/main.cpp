//
// Created by katussska on 10/5/23.
//
#include "headers/Tree.h"

using namespace std;

int main() {

    // Define a vector of keys for testing
    vector<int> keys = {3, 8, 12, 15, 16, 19, 28, 32, 45, 50, 56, 61, 62, 64, 66, 77, 85, 86, 87, 88};

    // Create an instance of the Tree class
    Tree AVLTree;

    // Insert keys into the AVLTree
    for (int key: keys) {
        AVLTree.root = AVLTree.insert(AVLTree.root, key);
    }

    // Print the AVLTree structure
    cout << "Printed AVLTree: " << endl;
    AVLTree.printTree(AVLTree.root, 3);
    cout << endl;

    // Search for a specific key in the AVLTree
    Tree::search(AVLTree.root, 32);
    cout << endl;

    // Delete a specific key from the AVLTree
    AVLTree.deleteNode(AVLTree.root, 32);

    // Search for the deleted key (check if it's not present)
    Tree::search(AVLTree.root, 32);
    cout << endl;

    // Print the AVLTree structure after deletion
    cout << "Printed AVLTree after delete: " << endl;
    AVLTree.printTree(AVLTree.root, 0);
    cout << endl;

    return 0;
}

