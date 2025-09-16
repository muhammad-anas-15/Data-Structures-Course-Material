#include <iostream>
#include <queue>
using namespace std;

class Node 
{
    public:
        int data;
        Node *right, *left;

        Node(int val) 
        {
            data = val;
            right = left = NULL;
        }
};

class Tree 
{
    private:
        Node* root;

    public:
        
        Tree() 
        {
            root = NULL;
        }

        bool isEmpty() 
        {
            return root == NULL;
        }
        
       
        void levelOrderInsert(int val)  // Level-order insert function with BST conditions
        {
            Node* newNode = new Node(val);
            
            if (root == NULL) 
            {
                root = newNode;
                return;
            }

            queue<Node*> q;
            q.push(root);

            while (!q.empty()) 
            {
                Node *current = q.front();
                q.pop();

                
                if (val < current->data) // Check if the new node should go to the left
                {
                    if (current->left == NULL) 
                    {
                        current->left = newNode;
                        return;
                    } 
                    else 
                    {
                        q.push(current->left);
                    }
                } 
                
                else if (val > current->data) // Check if the new node should go to the right
                {
                    if (current->right == NULL) 
                    {
                        current->right = newNode;
                        return;
                    } 
                    else 
                    {
                        q.push(current->right);
                    }
                }
                
                else // If the value already exists, do nothing
                {
                    return;
                }
            }
        }
        
        // Function for level-order traversal to display tree
        void levelOrderTraversal()
        {
            if(root == NULL)
            {
                cout << "Tree is empty." << endl;
                return;
            }
            
            queue<Node*> q;
            q.push(root);
            
            while(!q.empty())
            {
                Node *current = q.front();
                q.pop();
                cout << current->data << " ";
                
                if(current->left != NULL)
                {
                    q.push(current->left);
                }
                if(current->right != NULL)
                {
                    q.push(current->right);
                }
            }
            cout << endl;
        }
        
        Node* getRoot() 
        {
            return root;
        }
};

int main() 
{
    Tree T1;

    T1.levelOrderInsert(50);
    T1.levelOrderInsert(30);
    T1.levelOrderInsert(70);
    T1.levelOrderInsert(20);
    T1.levelOrderInsert(40);
    T1.levelOrderInsert(60);
    T1.levelOrderInsert(80);

    cout << "Level-order traversal after inserts: ";
    T1.levelOrderTraversal();

    return 0;
}
