#include <iostream>
#include <algorithm>

class Node {
public:
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int key) : key(key), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
public:
    Node* root;

    AVLTree() : root(nullptr) {}

    int height(Node* node) {
        return node ? node->height : 0;
    }

    int balanceFactor(Node* node) {
        return height(node->right) - height(node->left);
    }

    void fixHeight(Node* node) {
        node->height = std::max(height(node->left), height(node->right)) + 1;
    }

    Node* rotateLeft(Node* q) {
        Node* p = q->right;
        q->right = p->left;
        p->left = q;
        fixHeight(q);
        fixHeight(p);
        return p;
    }

    Node* rotateRight(Node* p) {
        Node* q = p->left;
        p->left = q->right;
        q->right = p;
        fixHeight(p);
        fixHeight(q);
        return q;
    }

    Node* balance(Node* node) {
        fixHeight(node);
        if (balanceFactor(node) == 2) {
            if (balanceFactor(node->right) < 0) {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }
        if (balanceFactor(node) == -2) {
            if (balanceFactor(node->left) > 0) {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        }
        return node;
    }

    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else {
            node->right = insert(node->right, key);
        }
        return balance(node);
    }

    void insert(int key) {
        root = insert(root, key);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        std::cout << node->key << " ";
        inorder(node->right);
    }

    void inorder() {
        inorder(root);
        std::cout << std::endl;
    }
};

int main() {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    std::cout << "In-order traversal of the constructed AVL tree is: ";
    tree.inorder();

    return 0;
}
