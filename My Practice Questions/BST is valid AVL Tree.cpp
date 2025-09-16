#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    int height;

    Node(int val) {
        data = val;
        left = right = nullptr;
        height = 1;
    }
};

class AVLTree {
private:
    Node* root;

public:
    AVLTree() {
        root = nullptr;
    }

    // Insert method
    void insert(int val) {
        root = insert(root, val);
    }

    Node* insert(Node* node, int val) 
	{
        if (node == nullptr) {
            return new Node(val);
        } else if (val < node->data) {
            node->left = insert(node->left, val);
        } else if (val > node->data) {
            node->right = insert(node->right, val);
        } else {
            return node; // Equal keys are not allowed
        }

        // Update height of the current node
        node->height = 1 + maxHeight(height(node->left), height(node->right));

        // Check balance and fix if necessary
        return node;
    }

    // Utility function to get the height of a node
    int height(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    // Manually implementing maxHeight instead of using std::max
    int maxHeight(int a, int b) {
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }

    // Method to check if the tree is balanced (AVL)
    bool isAVL(Node* node) {
        if (node == nullptr) return true;

        // Check the balance factor of the node
        int balance = getBalance(node);

        // If the balance factor is outside the range of -1 to 1, it's not an AVL tree
        if (balance < -1 || balance > 1)
            return false;

        // Recursively check left and right subtrees
        return isAVL(node->left) && isAVL(node->right);
    }

    // Method to get the balance factor of a node
    int getBalance(Node* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    // Method to traverse the tree in order (in-order)
    void inOrder(Node* root) {
        if (root == nullptr) return;

        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    void traverseInOrder() {
        cout << "\nInorder Traversal: ";
        inOrder(root);
        cout << endl;
    }

    // Method to check if the tree is AVL
    bool checkAVL() {
        return isAVL(root);
    }
};

int main() {
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    tree.traverseInOrder();

    if (tree.checkAVL()) {
        cout << "The tree is a valid AVL tree." << endl;
    } else {
        cout << "The tree is NOT a valid AVL tree." << endl;
    }

    return 0;
}
