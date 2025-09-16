#include <iostream>
#include <limits.h>
using namespace std;

// Definition of Node
struct Node 
{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Helper function to check if the tree is a valid BST
bool isValidBSTHelper(Node* node, int minVal, int maxVal) 
{
    // Base case: If the node is NULL, it's valid
    if (!node) return true;

    // Check the BST condition
    if (node->data <= minVal || node->data >= maxVal) return false;

    // Recursively check the left and right subtrees
    return isValidBSTHelper(node->left, minVal, node->data) &&
           isValidBSTHelper(node->right, node->data, maxVal);
}

// Function to check if a binary tree is a valid BST
bool isValidBST(Node* root) {
    return isValidBSTHelper(root, INT_MIN, INT_MAX);
}

int main() {
    // Construct the binary tree
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    // Check if the binary tree is a valid BST
    if (isValidBST(root)) {
        cout << "The binary tree is a valid BST." << endl;
    } else {
        cout << "The binary tree is not a valid BST." << endl;
    }

    return 0;
}
