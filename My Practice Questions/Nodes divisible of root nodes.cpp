#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* right;
    Node* left;
    Node* parent;

    Node(int d) 
    {
        data = d;
        right = left = parent = NULL; 
    }
};

class BinaryTree
{
private:
    Node *root;

public:
    BinaryTree()
    {
        root = NULL;
    }
    
    bool isEmpty()
    {
        return root == NULL;
    }
    
    void setLeft(Node* p, int x)
    {
        if (p != NULL && p->left == NULL)
        { 
            p->left = new Node(x);
            p->left->parent = p;
        }
    }

    void setRight(Node* p, int x)
    {
        if (p != NULL && p->right == NULL)
        { 
            p->right = new Node(x);
            p->right->parent = p;
        }
    }

    Node* left(Node* p)
    {
        if (p != NULL) 
            return p->left;
        else 
            return NULL;
    }

    Node* right(Node* p)
    {
        if (p != NULL) 
            return p->right;
        else 
            return NULL;
    }

    Node* parent(Node* p)
    {
        if (p != NULL) 
            return p->parent;
        else
            return NULL;
    }

    Node* brother(Node* p)
    {
        if (p == NULL || p->parent == NULL) return NULL;
        if (p == p->parent->left) return p->parent->right;
        
        return p->parent->left;
    }

    int info(Node* p)
    {
        if (p != NULL) 
            return p->data;
        else 
            return -1;
    }

    Node* buildBinaryTree(Node* root)
    {
        cout << "Enter the Data (-1 to indicate no node): ";
        int data;
        cin >> data;

        if (data == -1)
            return NULL;

        root = new Node(data);

        cout << "Insert left of " << data << ": ";
        root->left = buildBinaryTree(root->left);

        cout << "Insert right of " << data << ": ";
        root->right = buildBinaryTree(root->right);

        return root;
    }

    int countDivisorNodes(Node* root, int rootValue)
    {
        if (root == NULL) 
            return 0;

        // Check if the current node's data is a divisor of the root's data
        int isDivisor = (rootValue % root->data == 0) ? 1 : 0;

        // Recursively calculate the total by adding up values from left and right subtrees
        return isDivisor + countDivisorNodes(root->left, rootValue) + countDivisorNodes(root->right, rootValue);
    }

    void startBuilding()
    {
        root = buildBinaryTree(root);
    }

    int countDivisors()
    {
        if (root == NULL) return 0;
        return countDivisorNodes(root, root->data);
    }
};

int main() 
{
    BinaryTree tree;

    tree.startBuilding();

    int result = tree.countDivisors();
    cout << "Number of nodes that are divisors of the root node: " << result << endl;

    return 0;
}
