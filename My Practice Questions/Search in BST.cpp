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

        bool isEmpty() 
        {
            return root == NULL;
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
                else // Value is already present.
                {
                    return;
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
        
        bool search(int val) 
        {
            Node* current = root;

            while (current != NULL) 
            {
                if (val == current->data) 
                {
                    return true; // Value found
                } 
                else if (val < current->data) 
                {
                    current = current->left; // Move to the left child
                } 
                else 
                {
                    current = current->right; // Move to the right child
                }
            }

            return false; // Value not found
        }

        void preOrder_NLR(Node *current = nullptr) 
        {
            if (current == NULL) 
            {
                current = root;
            }
            if (current != NULL) 
            {
                cout << current->data << " ";
                preOrder_NLR(current->left);
                preOrder_NLR(current->right);
            }
        }
        
        void inOrder_LNR(Node *current = nullptr) 
        {
            if (current == nullptr) 
            {
                current = root;
            }
            if (current != NULL) 
            {
                inOrder_LNR(current->left);
                cout << current->data << " ";
                inOrder_LNR(current->right);
            }
        }

        void postOrder_LRN(Node *current = nullptr) 
        {
            if (current == NULL) 
            {
                current = root;
            }
            if (current != NULL) 
            {
                postOrder_LRN(current->left);
                postOrder_LRN(current->right);
                cout << current->data << " ";
            }
        }

        Node* getRoot() 
        {
            return root;
        }
};

int main() 
{
    Tree T1;

    T1.insert(50);
    T1.insert(30);
    T1.insert(70);
    T1.insert(20);
    T1.insert(40);
    T1.insert(60);
    T1.insert(80);
    // Searching for elements
    int searchValue = 40;
    
    if (T1.search(searchValue)) 
    {
        cout << searchValue << " is found in the tree." << endl;
    } 
    else 
    {
        cout << searchValue << " is not found in the tree." << endl;
    }

    return 0;
}
