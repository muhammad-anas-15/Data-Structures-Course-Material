#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;          
    Node *left, *right; 
    int height;      

    Node(int k) 
	{
        data = k;
        left = right = NULL;
        height = 1;
    }
};

class AVLTree 
{
private:
    Node* root; 

public:
    AVLTree() 
	{
        root = NULL;
    }

    void insert(int key) 
	{
        root = insert(root, key);
    }

    void deleteNode(int key) 
	{
        root = deleteNode(root, key);
    }

    void inOrder() 
	{
        inOrder(root);
        cout << endl;
    }

    int height(Node* N) 
	{
        if (N == NULL) 
		{
            return 0;
        }
        return N->height;
    }

    Node* rightRotate(Node* y) 
	{
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    Node* leftRotate(Node* x) 
	{
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    int getBalance(Node* N) 
	{
        if (N == NULL) 
		{
            return 0;
        }
        return height(N->left) - height(N->right);
    }

    Node* insert(Node* node, int key) 
	{
        if (node == NULL) 
		{
            return new Node(key);
        }

        if (key < node->data) 
		{
            node->left = insert(node->left, key);
        } 
		else if (key > node->data) 
		{
            node->right = insert(node->right, key);
        } 
		else 
		{
            return node; 
        }

        // Update height of this ancestor node
        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        // If this node becomes unbalanced, then there are 4 cases

        // Left Left Case
        if (balance > 1 && key < node->left->data) 
		{
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && key > node->right->data) 
		{
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && key > node->left->data) 
		{
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->data) 
		{
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* minValueNode(Node* node) 
	{
        Node* current = node;
        
        while (current->left != NULL) 
		{
            current = current->left;
        }
        return current;
    }

    Node* deleteNode(Node* root, int key)
	{
        if (root == NULL) 
		{
            return root;
        }

        // Find the node to be deleted
        if (key < root->data) 
		{
            root->left = deleteNode(root->left, key);
        } 
		else if (key > root->data) 
		{
            root->right = deleteNode(root->right, key);
        } 
        
		else 
		{
            // Node with only one child case
            if ((root->left == NULL) || (root->right == NULL))
			{
				Node *temp ; 
				
                if (root->left != NULL) 
                {
                        temp = root->left; // Assign left child if it exists
                 } 
                 else 
                {
                        temp = root->right; // Otherwise, assign right child
                }

                // No child case
                if (temp == NULL) 
				{
                    temp = root;
                    root = NULL;
                } 
				else 
				{
                    *root = *temp; // Copy the contents of the non-empty child
                }
                delete temp;
            } 
			else 
			{
                // Node with two children: Get the inorder successor (smallest in the right subtree)
                Node* temp = minValueNode(root->right);

                // Copy the inorder successor's data to this node
                root->data = temp->data;

                // Delete the inorder successor
                root->right = deleteNode(root->right, temp->data);
            }
        }

        if (root == NULL) 
		{
            return root;
        }

        // Update height of the current node
        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        // If this node becomes unbalanced, then there are 4 cases

        // Left Left Case
        if (balance > 1 && getBalance(root->left) >= 0) 
		{
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && getBalance(root->right) <= 0) 
		{
            return leftRotate(root);
        }
        
        // Left Right Case
        if (balance > 1 && getBalance(root->left) < 0) 
		{
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }


        // Right Left Case
        if (balance < -1 && getBalance(root->right) > 0) 
		{
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void inOrder(Node* root) 
	{
        if (root == NULL) 
		{
            return;
        }
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
};

int main() 
{
    AVLTree tree;

    tree.insert(9);
    tree.insert(5);
    tree.insert(10);
    tree.insert(0);
    tree.insert(6);
    tree.insert(11);
    tree.insert(-1);
    tree.insert(1);
    tree.insert(2);

    cout << "Inorder traversal : ";
    tree.inOrder();  

    // Deleting a node
    tree.deleteNode(10);

    cout << "After Deletion Inorder traversal : ";
    tree.inOrder();  

    return 0;
}
