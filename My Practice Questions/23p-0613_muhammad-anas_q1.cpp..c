#include<iostream>
using namespace std;

class Node {
public:
    int data;
    int count_duplicates;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->count_duplicates = 1; // Initially count is 1
        left = NULL;
        right = NULL;
    }
};

class Tree
{
public:
    Node *root;
    int total_duplicates; // Track total number of duplicate insertions

    Tree()
    {
        root = NULL;
        total_duplicates = 0; // Initialize duplicate count
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

    // Insert method with duplicate counting
    Node* insert(Node *root, int key)
    {
        if (root == NULL)
        {
            return new Node(key);
        }
        if (key < root->data)
        {
            root->left = insert(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = insert(root->right, key);
        }
        else
        {
            // If key is equal to root->data, increment the count (duplicate)
            root->count_duplicates++;
            total_duplicates++; // Increment global duplicate counter
        }
        return root;
    }

    // In-order traversal
    void inOrder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inOrder(root->left);
        cout << root->data << "(" << root->count_duplicates << ") "; // Print count along with data
        inOrder(root->right);
    }

    // Delete method to handle all three cases
    Node* deleteNode(Node* root, int key)
    {
        if (root == NULL)
        {
            return root; // If the tree is empty or node not found
        }

        // Traverse to find the node to delete
        if (key < root->data)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        { // When the node to be deleted is found
            // Case 1: Node has no children (leaf node)
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            // Case 2: Node has one child
            else if (root->left == NULL)
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // Case 3: Node has two children
            else
            {
                Node* temp = minValueNode(root->right);
                root->data = temp->data; // Replace node data with inorder successor
                root->right = deleteNode(root->right, temp->data); // Delete inorder successor
            }
        }

        // Handle the case where we are deleting a node with duplicates
        if (key == root->data)
        {
            if (root->count_duplicates > 1)
            {
                root->count_duplicates--; // Decrement the duplicate count
                total_duplicates--; // Decrement global duplicate count
            }
            else
            {
                return deleteNode(root, key); // Proceed with normal deletion if no duplicates left
            }
        }

        return root;
    }

    // Find the node with the minimum value (used in case 3 for deletion)
    Node* minValueNode(Node* node)
    {
        Node* current = node;

        while (current && current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    // Method to delete a node and handle the case when a node has duplicates
    void deleteNodeWrapper(int key)
    {
        root = deleteNode(root, key);
    }
};

int main() {
    Tree t;
    // Inserting nodes into the tree
    t.root = t.insert(t.root, 50);
    t.root = t.insert(t.root, 30);
    t.root = t.insert(t.root, 20);
    t.root = t.insert(t.root, 40);
    t.root = t.insert(t.root, 70);
    t.root = t.insert(t.root, 60);
    t.root = t.insert(t.root, 80);

    // Inserting duplicates
    t.root = t.insert(t.root, 50);
    t.root = t.insert(t.root, 30);
    t.root = t.insert(t.root, 70);

    cout << "\nIn-order Traversal before deletion:\n";
    t.inOrder(t.root);
    cout << endl;

    // Deleting node with duplicates (50)
    t.deleteNodeWrapper(50);
    cout << "\nIn-order Traversal after deleting node 50:\n";
    t.inOrder(t.root);
    cout << endl;

    // Deleting node with no children (20)
    t.deleteNodeWrapper(20);
    cout << "\nIn-order Traversal after deleting node 20:\n";
    t.inOrder(t.root);
    cout << endl;

    // Deleting node with one child (30)
    t.deleteNodeWrapper(30);
    cout << "\nIn-order Traversal after deleting node 30:\n";
    t.inOrder(t.root);
    cout << endl;

    // Deleting node with two children (70)
    t.deleteNodeWrapper(70);
    cout << "\nIn-order Traversal after deleting node 70:\n";
    t.inOrder(t.root);
    cout << endl;

    // Display total duplicates count
    cout << "\nTotal number of duplicate insertions: " << t.total_duplicates << endl;

    return 0;
}
