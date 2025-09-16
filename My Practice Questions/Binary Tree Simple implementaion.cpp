#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* right;
    Node* left;

    Node(int d) 
	{
        data = d;
        right = left = NULL; 
    }
};

Node* Build_Binary_Tree(Node* root) {
	
    cout << "Enter the Data (-1 to indicate no node): " << endl;
    int data;
    cin >> data;

    
    if (data == -1) // If data is -1, no node should be created
	{
        return NULL;
    }

    
    root = new Node(data); // Create a new Node

    cout << "Enter data for inserting at left of " << data << ": ";
    
    root->left = Build_Binary_Tree(root->left);// Recursive call for building the left subtree

    cout << "Enter data for inserting at right of " << data << ": ";
   
    root->right = Build_Binary_Tree(root->right); // Recursive call for building the right subtree

    return root;
}

void preOrder(Node* root) 
{
    if (root == NULL) 
	{
        return;
    } 
	else 
	{
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) 
{
    if (root == NULL) 
	{
        return;
    } 
	else 
	{
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(Node* root) 
{
    if (root == NULL) 
	{
        return;
    } 
	else 
	{
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() 
{
    Node* root = NULL;

    // Creating the binary tree
    root = Build_Binary_Tree(root);

    // Display traversals (optional)
    cout << "\nPreorder Traversal: ";
    preOrder(root);
    
    cout << "\nInorder Traversal: ";
    inOrder(root);
    
    cout << "\nPostorder Traversal: ";
    postOrder(root);
    
    cout << endl;

    return 0;
}
