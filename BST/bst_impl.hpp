#include "bst.hpp"

inline Node::Node(int key)
    : key(key), left(nullptr), right(nullptr)
{
}

inline BST::BST(int key)
    : root(new Node(key))
{
}

inline BST::BST()
{
}

inline Node *BST::search(Node* node,int key)
{
    if (!node || node->key == key) {
        return node;
    }

    if (node->key > key) {
        return search(node->left, key);
    }
    return search(node->right, key);
}

inline Node *BST::search_it(Node *node, int key)
{
    while (node && node->key == key) {
        if (node->key > key) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    return node;
}

inline Node *BST::min_node(Node *node)
{
    if (!node->left || !node) {
        return node;
    }

    return min_node(node->left);
}

inline Node *BST::min_node_it(Node *node)
{
    while (node->left && node) {
        node = node->left;
    }
    return node;
}

inline Node *BST::max_node(Node *node)
{
    if (!node->right || !node) {
        return node;
    }

    return max_node(node->right);
}

inline Node *BST::max_node_it(Node *node)
{
    while (node->right && node) {
        node = node->right;
    }
    return node;
}

inline void BST::inorder_traversal_it(Node *node)
{
    std::stack<Node*> stk;
    Node* curr = node;
    while (curr || !stk.empty()) {
        while (curr) {
            stk.push(curr);
            curr = curr->left;
        }
        curr = stk.top();
        std::cout << curr->key << " ";
        stk.pop();
        curr = curr->right;
    }
}

inline void BST::preorder_traversal_it(Node *node)
{
}

inline void BST::postorder_traversal_it(Node *node)
{
}

inline Node *BST::successor(Node *node)
{
    if (!node) {
        return nullptr;
    }

    if (node->right) {
        return min_node(node->right);
    }

    Node* succ = root;
    while (succ->left && succ->left != node) {
        if (succ->key > node->key) {
            succ = succ->left;
        }
        else {
            succ = succ->right;
        }
    }
    if (succ == node) {
        return nullptr;
    }

    return succ;
}

inline Node *BST::predecessor(Node *node)
{
    if (!node) {
        return nullptr;
    }

    if (node->left) {
        return max_node(node->left);
    }

    Node* pred = root;
    while (pred->right && pred->right != node) {
        if (pred->key > node->key) {
            pred = pred->left;
        }
        else {
            pred = pred->right;
        }
    }

    if (pred == node) {
        return nullptr;
    }

    return pred;
}

inline Node *BST::insert(Node *node, int key)
{
    if (!node) {
        return new Node(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }

    return node;
}

inline void BST::insert(int key)
{
    root = insert(root, key);
}

inline void BST::insert_it(int key)
{
    Node* new_node = new Node(key);
    if (!root) {
        root = new_node;
        return;
    }

    Node* node = root;
    while (node) {
        if (key <= node->key) {
            if (node->left) {
                node = node->left;
            }
            else {
                node->left = new_node;
                break;
            }
        }
        else if (key > node->key) {
            if (node->right) {
                node = node->right;
            }
            else {
                node->right = new_node;
                break;
            }
        }
    }
}

inline Node* BST::remove(int key, Node* node) {
    Node* tmp;
    if (!node) {
        return nullptr;
    }
    else if (key < node->key) {
        node->left = remove(key, node->left);
    }
    else if (key > node->key) {
        node->right = remove(key, node->right);
    }
    else if (node->left && node->right) {
        tmp = min_node(node->right);
        node->key = tmp->key;
        node->right = remove(node->key, node->right);
    }
    else {
        tmp = node;
        if (!node->left) {
            node = node->right;
        }
        else if (!node->right) {
            node = node->left;
        }
        delete tmp;
    }

    return node;
}

inline void BST::remove(int key)
{
    root = remove(key, root);
}

inline void BST::inorder_traversal(Node *node)
{
    if (node) {
        inorder_traversal(node->left);
        std::cout << node->key << " ";
        inorder_traversal(node->right);
    }
}

inline void BST::preorder_traversal(Node *node)
{
    if (node) {
        std::cout << node->key << " ";
        preorder_traversal(node->left);
        preorder_traversal(node->right);
    }
}

inline void BST::postorder_traversal(Node *node)
{
    if (node) {
        postorder_traversal(node->left);
        postorder_traversal(node->right);
        std::cout << node->key << " ";
    }   
}

inline int BST::height(Node *node)
{
    if (!node) {
        return 0;
    }
    int left_height = height(node->left);
    int right_height = height(node->right);

    if (left_height > right_height) {
        return left_height + 1;
    }
    else {
        return right_height + 1;
    }
}

inline void BST::print_current_level(Node *node, int level)
{
    if (!node) {
        return;
    }
    if (level == 1) {
        std::cout << node->key << " ";
    }
    else if (level > 1) {
        print_current_level(node->left, level - 1);
        print_current_level(node->right, level - 1);
    }
}

inline void BST::level_order_traversal(Node *node)
{
    for (int i = 1; i <= height(node); ++i) {
        print_current_level(node, i);
    }
}

inline Node* BST::get_root()
{
    return root;
}