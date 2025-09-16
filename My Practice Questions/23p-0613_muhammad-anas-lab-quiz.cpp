#include<iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
	{
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
class Tree
{
	public:
		Node *root;

	public:
		Tree()
		{
			root = NULL;
		}

		//function to insert value in Tree
		Node* insert(Node *root, int key)
       {
         if (root == NULL)
          {
            return new Node(key);
          }

        else if (key < root->data)
        {
            root->left = insert(root->left, key);
        }

        else if (key > root->data)
        {
            root->right = insert(root->right, key);
        }

        return root;
    }

    //Function to check Binary Tree is valid BST or not
    bool isBST(Node *root, int min, int max) //take min and max value to check for valid BST
    {

        if (root == NULL) //if one element then it must be BST
        {
            return true;
        }

        //check if in root val is greater then the left sub tree and less then right subtree
        if (root->data > min && root->data < max)
        {
        	//recursively check for left subtree
            bool left = isBST(root->left, min, root->data);

            //recursively check for right subtree
            bool right = isBST(root->right, root->data, max);


            return left && right;
        }

        else //if above on any node condition fails then the Tree is not BST
        {
            return false;
        }
    }

};

int main()
{
	Tree t;

    //t.root = t.insert(t.root, 2);

    //t.root = t.insert(t.root, 3);
    //t.root = t.insert(t.root, 4);
    //t.root = t.insert(t.root, 5);
    //t.root = t.insert(t.root, 9);
    //t.root = t.insert(t.root, 7);

    Node *root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(1);

   // t.root = new Node(6);
    //root->left = new Node(9);
    //root->right = new Node(3);


    // Check if the tree is a BST and output the result
    if (t.isBST(t.root, INT_MIN, INT_MAX))
    {
        cout << "The tree is a valid BST." << endl;
    }
    else
    {
        cout << "The tree is not a valid BST." << endl;
    }

    return 0;
}
