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


        cout << "insert left of " << data <<endl;
        root->left = buildBinaryTree(root->left); // Recursive call for left child

        cout << "Where to insert right of " << data << "?\n";
        root->right = buildBinaryTree(root->right); // Recursive call for right child

        return root; // Return the newly created root node
    }





    //Function to check Binary Tree is valid BST or not
    bool isBST(Node *root, int min, int max) //take min and max value to check for valid BST
    {

        if (root == NULL) //if one element then it must be BST
        {
            return true;
        }

        //check if in root val is greater then the left sub tree and less then right subtree
        if (root->data > min && root->data < max)
        {
        	//recursively check for left subtree
            bool left = isBST(root->left, min, root->data);

            //recursively check for right subtree
            bool right = isBST(root->right, root->data, max);


            return left && right;
        }

        else //if above on any node condition fails then the Tree is not BST
        {
            return false;
        }
    }
};

int main()
{
    BinaryTree tree;


    tree.startBuilding();// Creating the binary tree

    // Check if the tree is a BST and output the result
    if (t.isBST(root, INT_MIN, INT_MAX))
    {
        cout << "The tree is a valid BST." << endl;
    }
    else
    {
        cout << "The tree is not a valid BST." << endl;
    }

    return 0;

    return 0;
}
