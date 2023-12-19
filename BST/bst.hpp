#ifndef BST_H
#define BST_H

#include <iostream>
#include <stack>

struct Node {
    Node(int key);

    int key;
    Node* left;
    Node* right;
};

class BST {
public:
    BST(int key);
    BST(); 
    Node* search(Node* node, int key);
    Node* min_node(Node* node);
    Node* max_node(Node* node);
    Node* successor(Node* node);
    Node* predecessor(Node* node);
    void insert(int key);
    void remove(int key);
    void inorder_traversal(Node* node);
    void preorder_traversal(Node* node);
    void postorder_traversal(Node* node);
    void level_order_traversal(Node* node);
    int height(Node* node);
    void print_current_level(Node* node, int level);
    Node* get_root();
    void inorder_traversal_it(Node* node);

private:
    Node* insert(Node* node, int key);
    Node* remove(int key, Node* node);
    void insert_it(int key);
    Node* search_it(Node* node, int key);
    Node* min_node_it(Node* node);
    Node* max_node_it(Node* node);
    Node* root = nullptr;
};

#include "bst_impl.hpp"
#endif