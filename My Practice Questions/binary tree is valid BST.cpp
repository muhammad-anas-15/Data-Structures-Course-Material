#include <iostream>
#include<climits>
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

    
    void preOrder(Node* root) // Pre-order traversal
	{
        if (root == NULL) 
            return;
            
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    
    void inOrder(Node* root) // In-order traversal 
	{
        if (root == NULL) 
            return;
            
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    
    void postOrder(Node* root) // Post-order traversal
	{
        if (root == NULL) 
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }

    
    void startBuilding() // Public method to start building the tree
	{
        root = buildBinaryTree(root);
    }

    
    void traversePreOrder() // Public methods for traversal
	{
        cout << "\nPreorder Traversal: ";
        preOrder(root);
    }

    void traverseInOrder() 
	{
        cout << "\nInorder Traversal: ";
        inOrder(root);
    }

    void traversePostOrder() 
	{
        cout << "\nPostorder Traversal: ";
        postOrder(root);
    }
    
     // Check if the tree is a valid BST
    bool isBST(Node *root, int min, int max) 
    {
        // Base case
        if (root == NULL) 
        {
            return true;
        }
        
        if (root->data > min && root->data < max) 
        {
            bool left = isBST(root->left, min, root->data);
            bool right = isBST(root->right, root->data, max);
            
            return left && right;
        } 
        else 
        {
            return false;
        }
    }
    
    bool checkvalididty()
    {
    	return isBST(root, INT_MIN, INT_MAX) ;
	}

};

int main() 
{
    BinaryTree tree;

    
    tree.startBuilding();// Creating the binary tree
    
    if(tree.checkvalididty())
    {
    	cout<<"Valid BST.";
	}
	
	else
	{
		cout<<"\n\nNot BST.";
	}
	

    // Display traversals
    tree.traversePreOrder();
    tree.traverseInOrder();
    tree.traversePostOrder();
    cout << endl;

    return 0;
}
