#include<iostream>
using namespace std;

class Node // node class implementation
{
	public:
		int data;
		Node *left , *right;
		
		Node(int val)
		{
			data = val;
			left = right = NULL;
		}
		
};
class BinarySearchTree // BST class implementation
{
	public:
		
		Node *root; // start of tree
		
		BinarySearchTree() //constructor
		{
			root = NULL;
		}
		
		Node *insert(Node *root, int val) //function for insertion in BST
	    {
           if (root == NULL) 
		   {
            return new Node(val);
           } 
           
		else if (val < root->data) 
		  {
            root->left = insert(root->left, val);
          } 
          
		else if (val > root->data) 
		  {
            root->right = insert(root->right, val);
          }
          
        return root;
    }
    
    void deleteNode(Node *&root, int val)  // function for deletion from BST
    {
        Node *parent = NULL;
        Node *current = root;

        // Find the node to be deleted and its parent
        while (current != NULL && current->data != val) 
        {
            parent = current;
            if (val < current->data) 
            {
                current = current->left;
            } 
            else 
            {
                current = current->right;
            }
        }

        // Node not found
        if (current == NULL) 
        {
            cout << "Value not found in the tree.\n";
            return;
        }

        // Case 1: Node has no children (leaf node)
        if (current->left == NULL && current->right == NULL) 
        {
            if (current != root) 
            {
                if (parent->left == current) 
                {
                    parent->left = NULL;
                } 
                else 
                {
                    parent->right = NULL;
                }
            } 
            else 
            {
                root = NULL;
            }
            delete current;
        }
        
        // Case 2: Node has only one child
        else if (current->left != NULL && current->right == NULL) 
        {
            Node *temp = current->left;

            if (current != root) 
            {
                if (parent->left == current) 
                {
                    parent->left = temp;
                } 
                else 
                {
                    parent->right = temp;
                }
            } 
            else 
            {
                root = temp;
            }
            delete current;
        } 
        else if (current->left == NULL && current->right != NULL) 
        {
            Node *temp = current->right;

            if (current != root) 
            {
                if (parent->left == current) 
                {
                    parent->left = temp;
                } 
                else 
                {
                    parent->right = temp;
                }
            } 
            else 
            {
                root = temp;
            }
            delete current;
        }
        
        // Case 3: Node has two children
        else if (current->left != NULL && current->right != NULL) 
        {
            Node *predecessor = findMin(current->right);

            // Replace `current` with successor's data
            current->data = predecessor->data;

            // Remove successor node
            Node *predecessorParent = current->right; // Initialize successor's parent
            
            if (predecessorParent == predecessor) 
            {
                current->right = predecessor->right; // Bypass the successor
            } 
            else 
            {
                while (predecessorParent->left != predecessor) 
                {
                    predecessorParent = predecessorParent->left;
                }
                predecessorParent->left = predecessor->right; // Bypass the successor
            }
            delete predecessor; // Delete the in-order successor
        }
    }

        
    Node* findMin(Node *node)  // function to find inorder predecessor
    {
        while (node && node->left) 
        {
            node = node->left;
        }
        return node;
    }    
        

    
    void inOrder(Node *root) //function for inorder traversal
	{
        if (root == NULL) 
		{
            return;
        }
        
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
    
    int height(Node* node) //function for calculating height
    {
        if (node == NULL) 
            return -1; // 
        
        // Calculate height of left and right subtrees recursively
        int leftHeight = height(node->left);
        
        int rightHeight = height(node->right);

        // Height of node is 1 + maximum of left and right subtree heights
        return 1 + max(leftHeight, rightHeight);
    }

   void Path(Node *root , int node) //function for finding and printing path
   {
   	 if(root == NULL)
   	 {
   	 	return ;
	 }
	 if(root->data  == node)
	 {
	 	return ;
	 }
	    //Path(root->left ,node);
        cout << root->data << " ";
        Path(root->right, node);
        
	 return ;
   }
    
};

int main() 
{
    BinarySearchTree T1;
    
    Node *root = T1.insert(NULL, 50);
    
    T1.insert(root, 30);
    T1.insert(root, 70);
    T1.insert(root, 20);
    T1.insert(root, 40);
    T1.insert(root, 60);
    T1.insert(root, 80);
    
    cout<<"\n\nIn-order Traversal:\n";
    T1.inOrder(root);
    
    T1.deleteNode(root, 30);
    
    cout<<"\n\nIn-order Traversal after deleting node 30 :\n";
    T1.inOrder(root);
    
    cout<<"\n\n Height of BST: ";
    cout<<T1.height(root);
    
    cout<<"\n\nPath to node 60 :";
    T1.Path(root ,60);

    return 0;
}
