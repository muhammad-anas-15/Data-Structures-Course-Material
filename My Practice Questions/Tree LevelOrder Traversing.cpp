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

        void insert(int val) 
		{
            if (root == NULL) 
			{
                root = new Node(val);
                return;
            }

            Node *current = root;
            Node *parent = NULL;

            while (current != NULL) 
			{
                parent = current;
                
                if (val < current->data) 
				{
                    current = current->left;
                } 
				else if (val > current->data) 
				{
                    current = current->right;
                } 
				else // Value is already present.
				{
                    return;
                }
            }

            if (val < parent->data) 
			{
                parent->left = new Node(val);
            } 
			else 
			{
                parent->right = new Node(val);
            }
        }
        
        void preOrder_NLR(Node *root) 
		{
            if (root != NULL) 
			{
                cout << root->data << " ";
                preOrder_NLR(root->left);
                preOrder_NLR(root->right);
            }
        }
        
        void inOrder_LNR(Node *root) 
		{
            if (root != NULL) 
			{
                inOrder_LNR(root->left);
                cout << root->data << " ";
                inOrder_LNR(root->right);
            }
        }

        void postOrder_LRN(Node *root) 
		{
            if (root != NULL) 
			{
                postOrder_LRN(root->left);
                postOrder_LRN(root->right);
                cout << root->data << " ";
            }
        }
        
        void Level_Order()
        {
        	if(root == NULL)
        	{
        		return;
        	}
        	
        	queue<Node*> q;
        	//stack(Node*) s
        	q.push(root);
        	
        	while(!q.empty())
			{
				Node* current = q.front();
				
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

    T1.insert(50);
    T1.insert(30);
    T1.insert(70);
    T1.insert(20);
    T1.insert(40);
    T1.insert(60);
    T1.insert(80);

    if (T1.isEmpty()) 
	{
        cout << "Tree is empty." << endl;
    } 
	else 
	{
        cout << "Tree is not empty." << endl;
    }

    // Display tree elements
    cout << "Pre-order traversal: ";
    T1.preOrder_NLR(T1.getRoot());
    
    cout << "\nIn-order traversal: ";
    T1.inOrder_LNR(T1.getRoot());
    
    cout << "\nPost-order traversal: ";
    T1.postOrder_LRN(T1.getRoot());
    
    cout << "\nLevel-order traversal: ";
    T1.Level_Order();
    cout << endl;

    return 0;
}
