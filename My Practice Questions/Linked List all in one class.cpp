#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *nextnode;

    Node(int val)
    {
        data = val;
        nextnode = NULL;
    }
};

class LinkedList
{
private:
    Node *head, *current, *previous;
    int LLsize;

public:
    LinkedList()
    {
        head = current = previous = NULL;
        LLsize = 0;
    }

    bool isEmpty()
    {
        return LLsize == 0;
    }

    void Add(int val)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = current = newnode;
        }
        else
        {
            current->nextnode = newnode;
            current = newnode;
        }
        LLsize++;
    }
    void Display()
    {
    	Node *p = head;
    	
    while (p) 
	{
        cout << p->data << " ";
        p = p->nextnode;
    }
    cout << endl;
	}
	
	int GetLength()
	{
	Node *p = head;
	
      int len = 0;
      
    while (p) 
	{
        len++;
        p = p->nextnode;
    }
    return len;
		
	}
	
	void Delete(int val)
    {
        if (isEmpty())
        {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        Node *temp = head;
        previous = NULL;

        // Case 1: Deleting the head node
        if (head->data == val)
        {
            head = head->nextnode;
            delete temp;
            LLsize--;
            return;
        }

        // Traverse the list to find the node to delete
        while (temp != NULL && temp->data != val)
        {
            previous = temp;
            temp = temp->nextnode;
        }

        // Case 2: Node not found
        if (temp == NULL)
        {
            cout << "Node with value " << val << " not found." << endl;
            return;
        }

        // Case 3: Deleting a node in the middle or end
        previous->nextnode = temp->nextnode;
        delete temp;
        LLsize--;
    }
};

int main()
{
    LinkedList L1;
    L1.Add(4);
    L1.Add(3);
    L1.Add(6);
    L1.Add(8);
    
    L1.Display();
    L1.Add(5);
    L1.Display();
}
