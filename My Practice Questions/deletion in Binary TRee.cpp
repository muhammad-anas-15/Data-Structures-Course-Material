/*
  Maintain deletion in Binary tree through level order traversing
  90
*/

#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int d) {
        data = d;
        left = right = parent = NULL;
    }
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() {
        root = NULL;
    }

    void setLeft(Node* p, int x) {
        if (p != NULL && p->left == NULL) {
            p->left = new Node(x);
            p->left->parent = p;
        }
    }

    void setRight(Node* p, int x) {
        if (p != NULL && p->right == NULL) {
            p->right = new Node(x);
            p->right->parent = p;
        }
    }

    Node* getRoot() {
        return root;
    }

    void startBuilding() {
        root = buildBinaryTree(root);
    }

    Node* buildBinaryTree(Node* root) {
        cout << "Enter the Data (-1 to indicate no node): ";
        int data;
        cin >> data;

        if (data == -1) {
            return NULL;
        }

        root = new Node(data);
        cout << "Insert left of " << data << endl;
        root->left = buildBinaryTree(root->left);
        cout << "Where to insert right of " << data << "?\n";
        root->right = buildBinaryTree(root->right);
        return root;
    }

    // Function to delete a node from binary tree
    void deleteNode(int key) {
        if (root == NULL) return; // If tree is empty

        // Step 1: Find the node to delete and the last node
        Node* target = NULL;
        Node* lastNode = NULL;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            lastNode = q.front();
            q.pop();

            // Check if this is the target node
            if (lastNode->data == key) {
                target = lastNode;
            }

            // Add children to the queue
            if (lastNode->left) q.push(lastNode->left);
            if (lastNode->right) q.push(lastNode->right);
        }

        // If the target node is found
        if (target != NULL) {
            target->data = lastNode->data; // Replace target with last node's data
            delete lastNode; // Delete last node
        }
    }

    void traversePreOrder(Node* root) {
        if (root == NULL) return;
        cout << root->data << " ";
        traversePreOrder(root->left);
        traversePreOrder(root->right);
    }

    void traverseInOrder(Node* root) {
        if (root == NULL) return;
        traverseInOrder(root->left);
        cout << root->data << " ";
        traverseInOrder(root->right);
    }

    void traversePostOrder(Node* root) {
        if (root == NULL) return;
        traversePostOrder(root->left);
        traversePostOrder(root->right);
        cout << root->data << " ";
    }
};

int main() {
    BinaryTree tree;
    tree.startBuilding(); // Building the binary tree

    cout << "Preorder Traversal Before Deletion: ";
    tree.traversePreOrder(tree.getRoot());
    cout << endl;

    int key;
    cout << "Enter the value of the node to delete: ";
    cin >> key;
    tree.deleteNode(key); // Delete the node

    cout << "Preorder Traversal After Deletion: ";
    tree.traversePreOrder(tree.getRoot());
    cout << endl;

    return 0;
}
