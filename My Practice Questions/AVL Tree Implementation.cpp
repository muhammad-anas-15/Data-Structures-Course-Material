#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    
    int height;

    Node(int val)
    {
        data = val;
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

    void insert(int val)
    {
        root = insert(root, val);
    }

    Node* insert(Node* node, int val)
    {
        if (node == NULL)
        {
            return new Node(val);
        }
        else if (val < node->data)
        {
            node->left = insert(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = insert(node->right, val);
        }
        
        else
        {
            return node; // Equal keys are not allowed
        }

        // Update height of this ancestor node
        node->height = 1 + max( height(node->left), height(node->right) );

        // Get the balance factor of this ancestor node to check whether
        // this node became unbalanced
        int balance = getBalance(node);

        // If this node becomes unbalanced, then there are 4 cases

        // Left Left Case
        if (balance > 1 && val < node->left->data)
        {
            return rightRotate(node);
        }

        // Right Right Case
        else if (balance < -1 && val > node->right->data)
        {
            return leftRotate(node);
        }

        // Left Right Case
        else if (balance > 1 && val > node->left->data)
		{
            node->left = leftRotate(node->left);

            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && val < node->right->data)
		{
            node->right = rightRotate(node->right);

            return leftRotate(node);
        }

        // Return the (unchanged) node pointer
        return node;
    }


    int height(Node* node)
    {
        if (node == NULL)
            return 0;
        return node->height;
    }

    Node* rightRotate(Node *y) // left left case
    {
        Node *x = y->left;
        Node *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        // Return new root
        return x;
    }

    // Utility function to perform a left rotation
    Node* leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    int getBalance(Node *node)
    {
        if (node == NULL)
        {
        	return 0;
		}

        return height(node->left) - height(node->right);
    }


    void inOrder(Node* root)
    {
        if (root == NULL)
            return;

        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    void traverseInOrder()
    {
        cout << "\nInorder Traversal: ";
        inOrder(root);
        cout << endl;
    }

};

int main()
{
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);


    tree.traverseInOrder();
    return 0;
}
