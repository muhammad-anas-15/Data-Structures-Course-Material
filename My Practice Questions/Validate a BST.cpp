#include <iostream>
#include <limits.h> // For INT_MIN and INT_MAX
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
    
    t.root = t.insert(t.root, 2); // Fix the root assignment here

    t.root = t.insert(t.root, 3);
    t.root = t.insert(t.root, 1);
    t.root = t.insert(t.root, 5);
    t.root = t.insert(t.root, 8);
    t.root = t.insert(t.root, 7);

    cout << "In-order traversal: ";
    t.inOrder(t.root);
    cout << endl;

    // Check if the tree is a BST and output the result
    if (t.isBST(t.root, INT_MIN, INT_MAX)) 
    {
        cout << "The tree is a valid BST." << endl;
    } 
    else 
    {
        cout << "The tree is not a valid BST." << endl;
    }

    return 0;
}
