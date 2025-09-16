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
            right = left = nullptr;
        }
};

class Tree 
{
    private:
        Node* root;

    public:
        
        Tree() 
        {
            root = nullptr;
        }

        bool isEmpty() 
        {
            return root == nullptr;
        }

        void insert(int val) 
        {
            if (root == nullptr) 
            {
                root = new Node(val);
                return;
            }

            Node *current = root;
            Node *parent = nullptr;

            while (current != nullptr) 
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
        
        void inOrder_LNR(Node *current) 
        {
            if (current == nullptr) 
            {
                return;
            }
            inOrder_LNR(current->left);
            cout << current->data << " ";
            inOrder_LNR(current->right);
        }

        void preOrder_NLR(Node *current) 
        {
            if (current == nullptr) 
            {
                return;
            }
            cout << current->data << " ";
            preOrder_NLR(current->left);
            preOrder_NLR(current->right);
        }

        void postOrder_LRN(Node *current) 
        {
            if (current == nullptr) 
            {
                return;
            }
            postOrder_LRN(current->left);
            postOrder_LRN(current->right);
            cout << current->data << " ";
        }
        
        void Delete(int val) 
        {
            root = deleteNode(root, val);
        }
        
        Node* deleteNode(Node* current, int val) 
        {
            if (current == NULL) 
            {
                return NULL;  // Node not found
            }

            if (val < current->data) 
            {
                current->left = deleteNode(current->left, val);
            } 
            else if (val > current->data) 
            {
                current->right = deleteNode(current->right, val);
            } 
            else // Node to be deleted is found
            {
        //Case 1: if node to delete is leaf node.	
                if (current->left == NULL && current->right == NULL) 
                {
                    delete current;
                    return NULL;
                }
                else if (current->left == NULL) 
                {
                    Node* temp = current->right;
                    delete current;
                    return temp;
                } 
                else if (current->right == NULL) 
                {
                    Node* temp = current->left;
                    delete current;
                    return temp;
                }
                else 
                {
                	// either find max or min
                    Node* temp = findMin(current->right);
                    
                    current->data = temp->data;
                    current->right = deleteNode(current->right, temp->data);
                }
            }
            return current;
        }
        
        Node* findMin(Node* current) 
        {
            while (current && current->left != nullptr) 
            {
                current = current->left;
            }
            return current;
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

    if (T1.isEmpty()) 
    {
        cout << "Tree is empty." << endl;
    } 
    else 
    {
        cout << "Tree is not empty." << endl;
    }

    cout << "\nInitial in-order traversal: ";
    T1.inOrder_LNR(T1.getRoot());

    cout << "\n\nDeleting 20...\n";
    T1.Delete(20);
    cout << "In-order traversal after deleting 20: ";
    T1.inOrder_LNR(T1.getRoot());

    cout << "\n\nDeleting 30...\n";
    T1.Delete(30);
    cout << "In-order traversal after deleting 30: ";
    T1.inOrder_LNR(T1.getRoot());

    cout << "\n\nDeleting 50...\n";
    T1.Delete(50);
    cout << "In-order traversal after deleting 50: ";
    T1.inOrder_LNR(T1.getRoot());

    cout << endl;
    return 0;
}
