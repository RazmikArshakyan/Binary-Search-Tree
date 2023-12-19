# Binary-Search-Tree
Implementation of Binary Search Tree

This C++ repository provides a simple implementation of a Binary Search Tree (BST). A Binary Search Tree is a binary tree data structure with the property that the key in each node must be greater than or equal to all keys stored in the left subtree and less than or equal to all keys stored in the right subtree.

This repository includes an implementation of a BST with various functions such as insertion, deletion, searching, and different methods of traversal.

Node(int key): Constructor for the Node class.
BST(int key): Constructor for the BST class with an initial key.
BST(): Default constructor for the BST class.
search(Node* node, int key): Recursive search for a key in the BST.
search_it(Node* node, int key): Iterative search for a key in the BST.
min_node(Node* node): Recursive finding of the node with the minimum key.
min_node_it(Node* node): Iterative finding of the node with the minimum key.
max_node(Node* node): Recursive finding of the node with the maximum key.
max_node_it(Node* node): Iterative finding of the node with the maximum key.
inorder_traversal_it(Node* node): Iterative in-order traversal.
successor(Node* node): Finding the successor of a given node.
predecessor(Node* node): Finding the predecessor of a given node.
insert(Node* node, int key): Recursive insertion of a key into the BST.
insert(int key): Public method for inserting a key into the BST.
insert_it(int key): Iterative insertion of a key into the BST.
remove(int key, Node* node): Recursive removal of a key from the BST.
remove(int key): Public method for removing a key from the BST.
inorder_traversal(Node* node): Recursive in-order traversal.
preorder_traversal(Node* node): Recursive pre-order traversal.
postorder_traversal(Node* node): Recursive post-order traversal.
height(Node* node): Recursive calculation of the height of the BST.
print_current_level(Node* node, int level): Helper function for printing a specific level of the BST.
level_order_traversal(Node* node): Level-order traversal of the BST.
get_root(): Accessor method to retrieve the root of the BST.
