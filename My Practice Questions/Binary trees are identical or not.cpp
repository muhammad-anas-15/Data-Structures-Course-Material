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

    void inOrder(Node* root)
    {
        if (root == NULL) 
            return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    void startBuilding()
    {
        root = buildBinaryTree(root);
    }

    void traverseInOrder() 
    {
        cout << "\nInorder Traversal: ";
        inOrder(root);
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
                q.push(current->left);

            // Enqueue right child
            if (current->right != NULL)
                q.push(current->right);
        }
        cout << endl;
    }

    // Function to check if two trees are identical
    bool isIdenticalTree(Node *root1, Node *root2)
    {
        if (root1 == NULL && root2 == NULL)
        {
            return true;
        }
        if (root1 == NULL && root2 != NULL)
        {
            return false;
        }
        if (root1 != NULL && root2 == NULL)
        {
            return false;
        }
        
        bool left = isIdenticalTree(root1->left, root2->left);
        bool right = isIdenticalTree(root1->right, root2->right);
        
        bool value = root1->data == root2->data;
        
        return left && right && value;
    }

    // Public function to start checking for identical trees
    bool checkIdenticalTrees(Node *otherRoot)
    {
        return isIdenticalTree(root, otherRoot);
    }
};

int main() 
{
    BinaryTree tree;

    // Build first binary tree
    cout << "Building first binary tree:\n";
    tree.startBuilding();

    // Display traversals
    tree.traverseInOrder();
    tree.levelOrder(); // Level-order traversal

    // Build second binary tree to compare
    BinaryTree otherTree;
    
    cout << "Building second binary tree to compare:\n";
    otherTree.startBuilding();

    // Check if both trees are identical
    if (tree.checkIdenticalTrees(otherTree.root))
    {
        cout << "\nThe trees are identical." << endl;
    }
    else
    {
        cout << "\nThe trees are not identical." << endl;
    }

    return 0;
}
