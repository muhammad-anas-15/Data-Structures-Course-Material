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
                q.push(current->left);

            // Enqueue right child
            if (current->right != NULL)
                q.push(current->right);
        }
        cout << endl;
    }
    
    // Function to calculate height of a node
    int height(Node* node)
    {
        if (node == NULL) 
            return -1; // Base case: empty tree has height -1 (or 0 if counting nodes)
        
        // Calculate height of left and right subtrees recursively
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        // Height of node is 1 + maximum of left and right subtree heights
        return 1 + max(leftHeight, rightHeight);
    }

    // Public function to calculate height of the tree
    int calculateHeight()
    {
        return height(root);
    }

    // Function to check if the binary tree is balanced
    bool isBalanced(Node* node)
    {
        if (node == NULL)
            return true; // Base case: empty tree is balanced
        
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        
        // Check if the current node is balanced and recurse for children
        return abs(leftHeight - rightHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right);
    }

    // Public function to check if the tree is balanced
    bool checkBalanced()
    {
        return isBalanced(root);
    }

    // Function to count unbalanced nodes in the tree
    int countUnbalancedNodes(Node* node)
    {
        if (node == NULL) 
            return 0;

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        int balance = leftHeight - rightHeight;

        // Check if the node is unbalanced
        bool isUnbalanced = abs(balance) > 1;

        int leftUnbalancedCount = countUnbalancedNodes(node->left);
        int rightUnbalancedCount = countUnbalancedNodes(node->right);

        return (isUnbalanced ? 1 : 0) + leftUnbalancedCount + rightUnbalancedCount;
    }

    // Public function to count unbalanced nodes in the tree
    int countUnbalanced()
    {
        return countUnbalancedNodes(root);
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
    
    // Calculate and display height of the binary tree
    cout << "\nHeight of the tree: " << tree.calculateHeight() << endl;

    // Check if the tree is balanced
    if (tree.checkBalanced())
        cout << "The tree is balanced." << endl;
    else
        cout << "The tree is not balanced." << endl;

    // Count and display the number of unbalanced nodes
    cout << "Number of unbalanced nodes: " << tree.countUnbalanced() << endl;

    return 0;
}
