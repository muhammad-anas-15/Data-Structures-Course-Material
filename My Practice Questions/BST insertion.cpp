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

class Tree 
{
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

    Node *insert(Node *root, int key) 
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
    Node *root = t.insert(NULL, 50);
    t.insert(root, 30);
    t.insert(root, 20);
    t.insert(root, 40);
    t.insert(root, 70);
    t.insert(root, 60);
    t.insert(root, 80);
    cout<<"\nIn-order Traversal:\n";
    t.inOrder(root);

    return 0;
}
