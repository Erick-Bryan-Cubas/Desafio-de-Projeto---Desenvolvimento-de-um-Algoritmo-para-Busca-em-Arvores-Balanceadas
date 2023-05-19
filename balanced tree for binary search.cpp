#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

Node* newNode(int data) {
  Node* node = new Node();
  node->data = data;
  node->left = nullptr;
  node->right = nullptr;
  return node;
}

bool isBalanced(Node* node) {
  if (node == nullptr) {
    return true;
  }

  int leftHeight = getHeight(node->left);
  int rightHeight = getHeight(node->right);

  return abs(leftHeight - rightHeight) <= 1;
}

int getHeight(Node* node) {
  if (node == nullptr) {
    return 0;
  }

  return 1 + max(getHeight(node->left), getHeight(node->right));
}

void rotateLeft(Node*& node) {
  Node* rightChild = node->right;
  node->right = rightChild->left;
  rightChild->left = node;

  node = rightChild;
}

void rotateRight(Node*& node) {
  Node* leftChild = node->left;
  node->left = leftChild->right;
  leftChild->right = node;

  node = leftChild;
}

void balance(Node*& node) {
  if (!isBalanced(node)) {
    if (getHeight(node->left) > getHeight(node->right)) {
      if (getHeight(node->left->left) > getHeight(node->left->right)) {
        rotateRight(node);
      } else {
        rotateLeft(node->left);
        rotateRight(node);
      }
    } else {
      if (getHeight(node->right->right) > getHeight(node->right->left)) {
        rotateLeft(node);
      } else {
        rotateRight(node->right);
        rotateLeft(node);
      }
    }
  }
}

void insert(Node*& root, int data) {
  if (root == nullptr) {
    root = newNode(data);
  } else {
    if (data < root->data) {
      insert(root->left, data);
    } else {
      insert(root->right, data);
    }

    balance(root);
  }
}

void inorder(Node* root) {
  if (root != nullptr) {
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }
}

int main() {
  Node* root = nullptr;

  insert(root, 10);
  insert(root, 5);
  insert(root, 15);
  insert(root, 2);
  insert(root, 7);
  insert(root, 12);
  insert(root, 17);

  cout << "Inorder traversal of the balanced tree: ";
  inorder(root);
  cout << endl;

  return 0;
}
