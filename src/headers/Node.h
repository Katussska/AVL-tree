//
// Created by katussska on 10/5/23.
//

#ifndef AVL_TREE_NODE_H
#define AVL_TREE_NODE_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// The Node class represents a single node in an AVL tree.
// It contains a key value, height information for balancing,
// and pointers to its left and right children.
class Node {
public:
    int key;
    int height;
    Node *left;
    Node *right;

    explicit Node(int key);

};


#endif //AVL_TREE_NODE_H
