#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node *right, *left;

    Node(int val) 
    {
        data = val;
        right = left = NULL;
    }
};

class Tree 
{
private:
    Node* root;

public:
    Tree() 
    {
        root = NULL;
    }

    void insert(int val) 
    {
        if (root == NULL) 
        {
            root = new Node(val);
            return;
        }

        Node *current = root;
        Node *parent = NULL;

        while (current != NULL) 
        {
            parent = current;
            if (val < current->data) 
            {
                current = current->left;
            } 
            else if (val > current->data) 
            {
                current = current->right;
            } 
            else 
            {
                return; // Value already exists
            }
        }

        if (val < parent->data) 
        {
            parent->left = new Node(val);
        } 
        else 
        {
            parent->right = new Node(val);
        }
    }

    void inOrder(Node* root) // In-order traversal 
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
    }
    
    Node* getRoot() 
    {
        return root;
    }
};

int main() 
{
    Tree T1;
    T1.insert(3);
    T1.insert(1);
    T1.insert(4);
    T1.insert(2);
    
    tree.traverseInOrder();

    return 0;
}
