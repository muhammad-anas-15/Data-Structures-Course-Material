#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) 
	{
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class Tree {
public:
    Node *root;

    Tree() 
	{
        root = NULL;
    }

    ~Tree() 
	{
        destroyTree(root);
    }

    void destroyTree(Node *node) 
	{
        if (node == NULL) 
		{
            return;
        }
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

    Node* search(Node *root, int key) 
	{
        if (root == NULL || root->data == key) 
		{
            return root;
        } 
		else if (key < root->data) 
		{
            return search(root->left, key);
        } 
		else 
		{
            return search(root->right, key);
        }
    }

    Node* insert(Node *root, int key) 
	{
        if (root == NULL) 
		{
            return new Node(key);
        } 
		else if (key < root->data) 
		{
            root->left = insert(root->left, key);
        } 
		else if (key > root->data) 
		{
            root->right = insert(root->right, key);
        }
        return root;
    }

    void inOrder(Node *root) 
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
    Tree t;
    
    Node *root = t.insert(NULL, 2);
    
    t.insert(root, 3);
    t.insert(root, 1);
    t.insert(root, 5);
    t.insert(root, 8);
    t.insert(root, 7);

    t.inOrder(root);
    return 0;
}
