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
    
    Node* findMin(Node *node) 
    {
        while (node && node->left) 
        {
            node = node->left;
        }
        return node;
    }

    void deleteNode(Node *&root, int val) 
    {
        Node *parent = NULL;
        Node *current = root;

        // Find the node to be deleted and its parent
        while (current != NULL && current->data != val) 
        {
            parent = current;
            if (val < current->data) 
            {
                current = current->left;
            } 
            else 
            {
                current = current->right;
            }
        }

        // Node not found
        if (current == NULL) 
        {
            cout << "Value not found in the tree.\n";
            return;
        }

        // Case 1: Node has no children (leaf node)
        if (current->left == NULL && current->right == NULL) 
        {
            if (current != root) 
            {
                if (parent->left == current) 
                {
                    parent->left = NULL;
                } 
                else 
                {
                    parent->right = NULL;
                }
            } 
            else 
            {
                root = NULL;
            }
            delete current;
        }
        
        // Case 2: Node has only one child
        else if (current->left != NULL && current->right == NULL) 
        {
            Node *temp = current->left;

            if (current != root) 
            {
                if (parent->left == current) 
                {
                    parent->left = temp;
                } 
                else 
                {
                    parent->right = temp;
                }
            } 
            else 
            {
                root = temp;
            }
            delete current;
        } 
        else if (current->left == NULL && current->right != NULL) 
        {
            Node *temp = current->right;

            if (current != root) 
            {
                if (parent->left == current) 
                {
                    parent->left = temp;
                } 
                else 
                {
                    parent->right = temp;
                }
            } 
            else 
            {
                root = temp;
            }
            delete current;
        }
        
        // Case 3: Node has two children
        else if (current->left != NULL && current->right != NULL) 
        {
            Node *successor = findMin(current->right);

            // Replace `current` with successor's data
            current->data = successor->data;

            // Remove successor node
            Node *successorParent = current->right; // Initialize successor's parent
            
            if (successorParent == successor) 
            {
                current->right = successor->right; // Bypass the successor
            } 
            else 
            {
                while (successorParent->left != successor) 
                {
                    successorParent = successorParent->left;
                }
                successorParent->left = successor->right; // Bypass the successor
            }
            delete successor; // Delete the in-order successor
        }
    }

    void inOrder(Node *root) 
    {        if (root == NULL) 
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
    
    root = t.insert(root, 3);
    t.insert(root, 1);
    t.insert(root, 5);
    t.insert(root, 8);
    t.insert(root, 7);
    t.insert(root, 9);
    t.inOrder(root);
    cout<<"\n";
    
    t.deleteNode(root, 8);
    
    cout<<"\nTree after deleting 8:\n";
    t.inOrder(root);
    return 0;
} 