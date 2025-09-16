#include <iostream>
#include <queue> // For the std::queue
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
    
    bool isEmpty() const
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
        return p != NULL ? p->left : NULL;
    }

    Node* right(Node* p)
    {
        return p != NULL ? p->right : NULL;
    }

    Node* parent(Node* p)
    {
        return p != NULL ? p->parent : NULL;
    }

    Node* brother(Node* p)
    {
        if (p == NULL || p->parent == NULL) return NULL;
        return p == p->parent->left ? p->parent->right : p->parent->left;
    }

    int info(Node* p)
    {
        return p != NULL ? p->data : -1;
    }

    Node* buildBinaryTree(Node* root)
    {
        cout << "Enter the Data (-1 to indicate no node): ";
        int data;
        cin >> data;

        if (data == -1)
        {
            return NULL;
        }

        root = new Node(data);

        cout << "Insert left of " << data << endl;
        root->left = buildBinaryTree(root->left);

        cout << "Insert right of " << data << endl;
        root->right = buildBinaryTree(root->right);

        return root;
    }

    void preOrder(Node* root)
    {
        if (root == NULL) 
            return;
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(Node* root)
    {
        if (root == NULL) 
            return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    void postOrder(Node* root)
    {
        if (root == NULL) 
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }

    void startBuilding()
    {
        root = buildBinaryTree(root);
    }

    void traversePreOrder()
    {
        cout << "\nPreorder Traversal: ";
        preOrder(root);
    }

    void traverseInOrder() 
    {
        cout << "\nInorder Traversal: ";
        inOrder(root);
    }

    void traversePostOrder() 
    {
        cout << "\nPostorder Traversal: ";
        postOrder(root);
    }

    // Level-order traversal function
    void levelOrder()
    {
        if (root == NULL) return; // If tree is empty

        queue<Node*> q; // Using standard queue for level-order traversal
        q.push(root);

        cout << "\nLevel-order Traversal: ";
        while (!q.empty())
        {
            Node* current = q.front();
            q.pop();

            cout << current->data << " ";

            // Enqueue left child
            if (current->left != NULL)
            {
            	q.push(current->left);
			}

            // Enqueue right child
            if (current->right != NULL)
            {
            	q.push(current->right);
			}
                
        }
        cout << endl;
    }
};

int main() 
{
    BinaryTree tree;

    // Build binary tree
    tree.startBuilding();

    // Display traversals
    tree.traversePreOrder();
    tree.traverseInOrder();
    tree.traversePostOrder();
    tree.levelOrder(); // Level-order traversal

    return 0;
}
