//
//  main.cpp
//  HW week 13
//
//  Created by Taanish Patel on 4/20/24.
//

#include <iostream>
using namespace std;

template <typename T>

class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
    };
    Node* root;

    void insert(Node* &node, const T& value) {
        if (node == nullptr) {
            node = new Node{value, nullptr, nullptr};
        } else if (value < node->data) {
            insert(node->left, value);
        } else {
            insert(node->right, value);
        }
    }

    int countNodes(Node* node) const {
        if (node == nullptr) {
            return 0;
        } else {
            return 1 + countNodes(node->left) + countNodes(node->right);
        }
    }

    int countLeafNodes(Node* node) const {
        if (node == nullptr) {
            return 0;
        } else if (node->left == nullptr && node->right == nullptr) {
            return 1;
        } else {
            return countLeafNodes(node->left) + countLeafNodes(node->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(const T& value) {
        insert(root, value);
    }

    int countNodes() const {
        return countNodes(root);
    }

    int countLeafNodes() const {
        return countLeafNodes(root);
    }
};

int main(int argc, const char * argv[]) {
    
    BinaryTree<int> intBinaryTree;

    intBinaryTree.insert(4);
    intBinaryTree.insert(1);
    intBinaryTree.insert(2);
    intBinaryTree.insert(6);
    intBinaryTree.insert(7);
    intBinaryTree.insert(9);
    intBinaryTree.insert(5);
    intBinaryTree.insert(0);

    cout << "Total number of nodes: " << intBinaryTree.countNodes() << endl;
    cout << "Total number of leaf nodes: " << intBinaryTree.countLeafNodes() << endl;
    
    return 0;
}

/*
 Output:
 
 Total number of nodes: 8
 Total number of leaf nodes: 4
 Program ended with exit code: 0
 
 */
