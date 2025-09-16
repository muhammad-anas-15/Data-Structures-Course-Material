#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Tree
{
public:
    int total_dup; // total number of duplicates across the tree

    Tree() // Constructor
    {
        total_dup = 0; // initialize duplicate count
    }

    // Insert function
    Node* insert(Node *node, int val)
    {
        if (node == NULL) // no node present in Tree
        {
            return new Node(val);
        }

        if (val < node->data) // inserted val is less than root val, so go left
        {
            node->left = insert(node->left, val);
        }
        else if (val > node->data) // inserted val is greater than root val, so go right
        {
            node->right = insert(node->right, val);
        }
        else // if val is already present, it is a duplicate
        {
            total_dup++; // Increment total duplicate count
        }
        return node;
    }

    void inOrder(Node *node) // In-order traversal
    {
        if (node == NULL)
            return;

        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    Node* deleteNode(Node* node, int key)
   {
    if (node == NULL) // If the tree is empty or node not found
        return node;

    // Traverse to find the node to delete
    if (key < node->data)
    {
        node->left = deleteNode(node->left, key);
    }
    else if (key > node->data)
    {
        node->right = deleteNode(node->right, key);
    }
    else // Node to delete found
    {
        // Decrease the duplicate count if the key is a duplicate
        if (key == node->data && total_dup > 0)
        {
            total_dup--;
            return node; // Do not delete the node, just reduce the duplicate count
        }

// Case 1: Node with no children
        if (node->left == NULL && node->right == NULL)
        {
            delete node;
            return NULL;
        }

// Case 2: Node with one child
        else if (node->left == NULL)
        {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == NULL)
        {
            Node* temp = node->left;
            delete node;
            return temp;
        }

// Case 3: Node with two children
        else
        {
            Node* temp = minValueNode(node->right); // Find the min value in the right subtree
            node->data = temp->data;               // Replace node's data with inorder successor
            node->right = deleteNode(node->right, temp->data); // Delete inorder successor
        }
    }

     return node;
    }


    Node* minValueNode(Node* node) // Find the minimum value node
    {
        Node* current = node;
        while (current && current->left != NULL)
        {
            current = current->left;
        }
        return current;
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

    // Insert duplicates
    t.insert(root, 50);
    t.insert(root, 30);
    t.insert(root, 70);

    // Display total duplicates
    cout << "Total number of duplicates after insertion: " << t.total_dup << endl;

    // In-order traversal before deletion
    cout << "\nIn-order Traversal before deletion:\n";
    t.inOrder(root);
    cout << endl;

    // Delete nodes
    root = t.deleteNode(root, 50); // Delete node with duplicates
    cout << "\nAfter deleting 50:\n";
    cout << "Total number of duplicates: " << t.total_dup << endl;
    t.inOrder(root);
    cout << endl;

    root = t.deleteNode(root, 30); // Delete node with duplicates
    cout << "\nAfter deleting 30:\n";
    cout << "Total number of duplicates: " << t.total_dup << endl;
    t.inOrder(root);
    cout << endl;

    root = t.deleteNode(root, 20); // Delete leaf node
    cout << "\nAfter deleting 20:\n";
    cout << "Total number of duplicates: " << t.total_dup << endl;
    t.inOrder(root);
    cout << endl;

    root = t.deleteNode(root, 70); // Delete node with duplicates
    cout << "\nAfter deleting 70:\n";
    cout << "Total number of duplicates: " << t.total_dup << endl;
    t.inOrder(root);
    cout << endl;

    return 0;
}

