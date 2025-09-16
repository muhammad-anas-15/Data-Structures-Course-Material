#include <iostream>
using namespace std;

// Class representing a node in the threaded binary tree
class Node 
{
public:
    int data;        
    
    Node* left;      
    Node* right;      
    int LTH, RTH;     // Flags for left thread/child and right thread/child

    // Constructor to initialize the node
    Node(int value) 
    {
        data = value;
        left = right = NULL;
        LTH = RTH = 0; // Initially, both left and right are threads
    }
};

class ThreadedBinaryTree 
{
  private:
    Node* root; 

  public:

    ThreadedBinaryTree() 
    {
        root = NULL;
    }

    // Function to insert a node into the threaded binary tree
    void insert(int value) 
    {
        if (root == NULL) 
        {
            root = new Node(value);
            return;
        }

        Node* parent = NULL;
        Node* current = root;

        // Traverse the tree to find the insertion point
        while (current != NULL) 
        {
            parent = current;
            
            if (value < current->data) 
            {
                if (current->left != NULL) 
                {
                    current = current->left;
                } 
                else 
                {
                    break;
                }
            } 
            else 
            {
                if (current->right != NULL) 
                {
                    current = current->right;
                } 
                else 
                {
                    break;
                }
            }
        }

        // Create the new node
        Node* newNode = new Node(value);

        // Insert the new node as a left or right child
        if (value < parent->data) 
        {
            newNode->left = parent->left;
            newNode->LTH = 1;

            newNode->right = parent;
            newNode->RTH = 1;

            parent->left = newNode;
            parent->LTH = 0;
        } 
        else 
        {
            newNode->right = parent->right;
            newNode->RTH = 1;

            newNode->left = parent;
            newNode->LTH = 1;

            parent->right = newNode;
            parent->RTH = 0;
        }
    }

    // Function to perform in-order traversal of the tree
    void inOrder() 
    {
        Node* current = leftmost(root);

        while (current != NULL) 
        {
            cout << current->data << " ";

            if (current->RTH == 1) 
            {
                current = current->right;
            } 
            else 
            {
                current = leftmost(current->right);
            }
        }
        
        cout << endl;
    }

    // Helper function to find the leftmost node in the tree
    Node* leftmost(Node* node) 
    {
        while (node != NULL && node->LTH == 0) 
        {
            node = node->left;
        }
        return node;
    }

    // Combined function to delete a value from the tree
    void remove(int value) 
    {
        Node* parent = NULL;
        Node* current = root;

        while (current != NULL) 
        {
            if (value == current->data) 
            {
                // Case 1: Node with no children
                if (current->LTH == 0 && current->RTH == 0) 
                {
                    if (parent == NULL) 
                    {
                        root = NULL;
                    }
                    else if (parent->left == current) 
                    {
                        parent->left = current->left;
                        parent->LTH = 1;
                    } 
                    else 
                    {
                        parent->right = current->right;
                        parent->RTH = 1;
                    }
                } 
                // Case 2: Node with one child (left or right child)
                else if (current->LTH == 1 && current->RTH == 0) 
                {
                    if (parent == NULL) 
                    {
                        root = current->right;
                    }
                    else if (parent->left == current) 
                    {
                        parent->left = current->right;
                    } 
                    else 
                    {
                        parent->right = current->right;
                    }
                } 
                else if (current->LTH == 0 && current->RTH == 1) 
                {
                    if (parent == NULL) 
                    {
                        root = current->left;
                    }
                    else if (parent->left == current) 
                    {
                        parent->left = current->left;
                    } 
                    else 
                    {
                        parent->right = current->left;
                    }
                } 
                // Case 3: Node with two children
                else 
                {
                    Node* successorParent = current;
                    Node* successor = current->right;
                    
                    while (successor->left != NULL && successor->LTH == 0) 
                    {
                        successorParent = successor;
                        successor = successor->left;
                    }

                    current->data = successor->data;
                    current = successor;
                    parent = successorParent;
                    continue;
                }

                delete current;
                return;
            }

            parent = current;

            if (value < current->data) 
            {
                if (current->LTH == 0) 
                {
                    current = current->left;
                } 
                else 
                {
                    break;
                }
            } 
            else 
            {
                if (current->RTH == 0) 
                {
                    current = current->right;
                } 
                else 
                {
                    break;
                }
            }
        }

        cout << "Value not found in the tree.\n";
    }
};

int main() {
    ThreadedBinaryTree T1;

    // Insert nodes into the tree
    T1.insert(20);
    T1.insert(10);
    T1.insert(30);
    T1.insert(5);
    T1.insert(15);
    T1.insert(25);
    T1.insert(35);

    // Perform in-order traversal
    cout << "In-order Traversal: ";
    T1.inOrder();

    // Delete a node from the tree
    T1.remove(10);
    cout << "After deleting 10: ";
    T1.inOrder();

    T1.remove(30);
    cout << "After deleting 30: ";
    T1.inOrder();

    return 0;
}
