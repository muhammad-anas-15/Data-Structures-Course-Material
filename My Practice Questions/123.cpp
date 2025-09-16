#include <iostream>
#include <climits> // For INT_MIN and INT_MAX
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node *parent; // Pointer to the parent node

    Node(int d)
    {
        data = d;
        right = left = parent = NULL;
    }
};

class BinaryTree
{
private:
    Node *root;

public:
    BinaryTree()
    {
        root = NULL;
    }

    bool isEmpty() // Method to check if the tree is empty
    {
        return root == NULL;
    }

    void startBuilding()
    {
        root = buildBinaryTree(root);
    }

    Node *buildBinaryTree(Node *root) // Method to build binary tree
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
    bool isBST(Node *node, int min, int max) // Take min and max value to check for valid BST
    {
        if (node == NULL) // An empty tree is a valid BST
        {
            return true;
        }

        // Check if the current node's data violates the min/max constraint
        if (node->data <= min || node->data >= max)
        {
            return false;
        }

        // Recursively check the left and right subtrees
        return isBST(node->left, min, node->data) && isBST(node->right, node->data, max);
    }

    void checkBST()
    {
        if (isBST(root, INT_MIN, INT_MAX))
        {
            cout << "The tree is a valid BST." << endl;
        }
        else
        {
            cout << "The tree is not a valid BST." << endl;
        }
    }
};

int main()
{
    BinaryTree tree;

    tree.startBuilding(); // Create the binary tree

    tree.checkBST(); // Check if the tree is a valid BST

    return 0;
}