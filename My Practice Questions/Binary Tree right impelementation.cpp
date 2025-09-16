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
    
    void setLeft(Node* p, int x) // set the left child
	{
        if (p != NULL && p->left == NULL) // Ensure there's no existing left child
		{ 
            p->left = new Node(x);
            p->left->parent = p; // Set parent of the new node
        }
    }


    void setRight(Node* p, int x)  // set the right child
	{
        if (p != NULL && p->right == NULL) // Ensure there's no existing right child
		{ 
            p->right = new Node(x);
            p->right->parent = p; // Set parent of the new node
        }
    }

    
    Node* left(Node* p) // Returns the left child of a node
    {
      if (p != NULL) 
	  {
         return p->left; // Return the left child if p is not null
      } 
	  else 
	  {
         return NULL; // Return NULL if p is null
      }
    }

    
    Node* right(Node* p) // Returns the right child of a node
    {
     if (p != NULL) 
	 {
        return p->right; // Return the right child if p is not null
     } 
	 else 
	 {
        return NULL; // Return NULL if p is null
     }
   }

    
    Node* parent(Node* p) // Returns the parent of a node
   {
    if (p != NULL) 
	{
        return p->parent; // Return the parent if p is not null
    } 
	else
	{
        return NULL; // Return NULL if p is null
    }
   }

    
    Node* brother(Node* p) // Returns the brother of a node
	{
        if (p == NULL || p->parent == NULL) return NULL; // No brother if no parent
        if (p == p->parent->left) return p->parent->right; // Return right child if p is left
        
        return p->parent->left; // Return left child if p is right
    }

    
    int info(Node* p) // Returns the content of the node
   {
    if (p != NULL) 
	{
        return p->data; // Return data if p is not null
    } 
	else 
	{
        return -1; // Return -1 if p is null
    }
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
};

int main() 
{
    BinaryTree tree;

    
    tree.startBuilding();// Creating the binary tree

    // Display traversals
    tree.traversePreOrder();
    tree.traverseInOrder();
    tree.traversePostOrder();
    cout << endl;

    return 0;
}
