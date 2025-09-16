#include <iostream>
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

        cout << "Insert left of " << data << ": ";
        root->left = buildBinaryTree(root->left); // Recursive call for left child

        cout << "Insert right of " << data << ": ";
        root->right = buildBinaryTree(root->right); // Recursive call for right child

        return root; // Return the newly created root node
    }

    // Function to find the maximum value in the binary tree
    int findMax(Node* node) 
    {
        if (node == NULL) 
        {
            return -1; // Return -1 if there are no nodes in the tree
        }

        // Initialize max with the current node's data
        int maxValue = node->data;

        // Find the maximum in the left subtree
        int leftMax = findMax(node->left);
        // If leftMax is greater than current maxValue, update it
        if (leftMax > maxValue)
        {
            maxValue = leftMax;
        }

        // Find the maximum in the right subtree
        int rightMax = findMax(node->right);
        // If rightMax is greater than current maxValue, update it
        if (rightMax > maxValue)
        {
            maxValue = rightMax;
        }

        return maxValue; // Return the maximum value found
    }

    // Public method to call the findMax function
    int getMaxValue() 
    {
        return findMax(root);
    }

    void traversePreOrder(Node* root) // Pre-order traversal
    {
        if (root == NULL) 
            return;

        cout << root->data << " ";
        traversePreOrder(root->left);
        traversePreOrder(root->right);
    }

    void startBuilding() // Public method to start building the tree
    {
        root = buildBinaryTree(root);
    }

    // Public method to start pre-order traversal
    void traversePreOrder() 
    {
        traversePreOrder(root); // Pass the root node to the traversal method
    }

    // Other methods (search, display traversals, etc.)...

};

int main() 
{
    BinaryTree tree;

    // Creating the binary tree
    tree.startBuilding();

    // Display traversals
    tree.traversePreOrder();
    cout << endl;

    // Find and display the maximum value in the binary tree
    int maxValue = tree.getMaxValue();
    cout << "Maximum value in the binary tree: " << maxValue << endl;

    return 0;
}
