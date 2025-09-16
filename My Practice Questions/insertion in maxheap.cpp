#include<iostream>
#include<queue>
using namespace std;

class Node
{
	public:
		Node *right;
		Node *left;
		int data;
		
		Node(int val)
		{
			data = val;
			right = left = NULL;
		}
};

class BinaryTree 
{
public:
    Node* root;  // Root of the tree

    BinaryTree() {
        root = NULL;
    }

    // Check if the binary tree is complete
    bool isComplete(Node* root) {
        if (root == NULL) return true;

        queue<Node*> q;
        q.push(root);

        bool flag = false;

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->left != NULL) {
                if (flag) return false;
                q.push(current->left);
            } else {
                flag = true;
            }

            if (current->right) {
                if (flag) return false;
                q.push(current->right);
            } else {
                flag = true;
            }
        }

        return true;
    }

    // Check if the binary tree satisfies the heap property
    bool isHeapProperty(Node* root, bool isMaxHeap) {
        if (!root) return true;

        if (root->left) {
            if ((isMaxHeap && root->data < root->left->data) || 
                (!isMaxHeap && root->data > root->left->data))
                return false;
        }

        if (root->right) {
            if ((isMaxHeap && root->data < root->right->data) || 
                (!isMaxHeap && root->data > root->right->data))
                return false;
        }

        return isHeapProperty(root->left, isMaxHeap) && isHeapProperty(root->right, isMaxHeap);
    }

    // Check if the binary tree is a Max-Heap or Min-Heap
    bool isHeap(Node* root, bool isMaxHeap) {
        return isComplete(root) && isHeapProperty(root, isMaxHeap);
    }
};
int main() 
{
    BinaryTree tree;

    // Example tree structure
    tree.root = new Node(50);
    tree.root->left = new Node(30);
    tree.root->right = new Node(20);
    tree.root->left->left = new Node(15);
    tree.root->left->right = new Node(10);
    tree.root->right->left = new Node(5);
    tree.root->right->right = new Node(3);

    // Check if the tree is a Max-Heap
    if (tree.isHeap(tree.root, true)) {
        cout << "The binary tree is a Max-Heap." << endl;
    } else if (tree.isHeap(tree.root, false)) {
        cout << "The binary tree is a Min-Heap." << endl;
    } else {
        cout << "The binary tree is NOT a Heap." << endl;
    }
    
    
    
    cout<<"\n\n";
     tree.root->right->right->left = new Node(8);
    // Check if the tree is a Max-Heap
    if (tree.isHeap(tree.root, true)) {
        cout << "The binary tree is a Max-Heap." << endl;
    } else if (tree.isHeap(tree.root, false)) {
        cout << "The binary tree is a Min-Heap." << endl;
    } else {
        cout << "The binary tree is NOT a Heap." << endl;
    }

    return 0;
}
