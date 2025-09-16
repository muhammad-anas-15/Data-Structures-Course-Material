#include <iostream>
#include <climits> // For INT_MIN and INT_MAX
using namespace std;

class Node
{
public:
    int data;
    Node* right;
    Node* left;
    Node* parent; // Pointer to the parent node

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

        cout << "Insert right of " << data << "?\n";
        root->right = buildBinaryTree(root->right); // Recursive call for right child

        return root; // Return the newly created root node
    }

    void startBuilding() // Public method to start building the tree
    {
        root = buildBinaryTree(root);
    }

    // Function to check if Binary Tree is a valid BST
    bool isBST(Node* root, int min, int max) // Take min and max value to check for valid BST
    {
        if (root == NULL) // If one element then it must be BST
        {
            return true;
        }

        // Check if root value is greater than left subtree and less than right subtree
        if (root->data > min && root->data < max)
        {
            // Recursively check for left subtree
            bool left = isBST(root->left, min, root->data);

            // Recursively check for right subtree
            bool right = isBST(root->right, root->data, max);

            return left && right;
        }
        else // If above condition fails on any node, the Tree is not a BST
        {
            return false;
        }
    }

    bool checkIfBST() // Helper function to check if the tree is a BST
    {
        return isBST(root, INT_MIN, INT_MAX);
    }
};

int main()
{
    BinaryTree tree;

    tree.startBuilding(); // Creating the binary tree

    // Check if the tree is a BST and output the result
    if (tree.checkIfBST())
    {
        cout << "The tree is a valid BST." << endl;
    }
    else
    {
        cout << "The tree is not a valid BST." << endl;
    }

    return 0;
}
