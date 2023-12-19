#include <iostream>

#include "bst.hpp"

int main() {
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Inorder Traversal: ";
    bst.inorder_traversal(bst.get_root());
    std::cout << std::endl;

    int key_to_search = 40;
    Node* search_result = bst.search(bst.get_root(), key_to_search);
    if (search_result) {
        std::cout << "Key " << key_to_search << " found in the tree." << std::endl;
    } else {
        std::cout << "Key " << key_to_search << " not found in the tree." << std::endl;
    }

    int key_to_remove = 30;
    bst.remove(key_to_remove);
    std::cout << "After removing key " << key_to_remove << ": ";
    bst.inorder_traversal(bst.get_root());
    std::cout << std::endl;

    int key_to_remove2 = 40;
    bst.remove(key_to_remove2);
    std::cout << "After removing key " << key_to_remove2 << ": ";
    bst.inorder_traversal(bst.get_root());
    std::cout << std::endl;
    
    BST bst2;

    bst2.insert(50);
    bst2.insert(30);
    bst2.insert(70);
    bst2.insert(20);
    bst2.insert(40);
    bst2.insert(60);
    bst2.insert(80);
    bst2.insert(10);
    std::cout << "Preorder traversal" << std::endl;
    bst2.preorder_traversal(bst2.get_root());
    std::cout << std::endl;
    std::cout << "Postorder traversal" << std::endl;
    bst2.postorder_traversal(bst2.get_root());
    std::cout << std::endl;
    std::cout << "Level order traversal" << std::endl;
    bst2.level_order_traversal(bst2.get_root());
    std::cout << std::endl;
    std::cout << "Inorder traversal iterative" << std::endl;
    bst2.inorder_traversal_it(bst2.get_root());
    std::cout << std::endl;

    return 0;
}
