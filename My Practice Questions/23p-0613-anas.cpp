#include <iostream>
#include <limits> // For INT_MIN and INT_MAX
using namespace std;

class Node {
public:
    int data;
    Node* right;
    Node* left;
    Node* parent; // Pointer to the parent node

    Node(int d) {
        data = d;
        right = left = parent = NULL;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    bool isEmpty() // Method to check if the tree is empty
    {
        return root == NULL;
    }

    Node* buildBinaryTree(Node* root) // Method to build binary tree
    {
        cout << "Enter the Data (-1 to indicate no node): ";
        int data;
        cin >> data;

        if (data == -1) // If data is -1, no node should be created
        {
            return NULL;
        }

        root = new Node(data); // Create a new Node for the current position

        cout << "Insert left of " << data << endl;
        root->left = buildBinaryTree(root->left); // Recursive call for left child

        cout << "Insert right of " << data << endl;
        root->right = buildBinaryTree(root->right); // Recursive call for right child

        return root; // Return the newly created root node
    }

    // Function to check if the Binary Tree is a valid BST or not
    bool isBST(Node* node, int min, int max) {
        if (node == NULL) // An empty tree is a BST
        {
            return true;
        }

        // Check if the current node's value is within the valid range
        if (node->data > min && node->data < max) {
            // Recursively check the left and right subtrees
            bool left = isBST(node->left, min, node->data);
            bool right = isBST(node->right, node->data, max);

            return left && right;
        } else {
            // If the condition fails, the tree is not a BST
            return false;
        }
    }
};

int main() {
    BinaryTree tree;

    tree.root = tree.buildBinaryTree(); // Build the binary tree

    // Check if the tree is a BST and output the result
    if (tree.isBST(tree.root, numeric_limits<int>::min(), numeric_limits<int>::max())) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is not a valid BST." << endl;
    }

    return 0;
}
