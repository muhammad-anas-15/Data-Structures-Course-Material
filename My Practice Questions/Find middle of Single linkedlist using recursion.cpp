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
    Node *head;
    int List_Size;

public:
    LinkedList()
    {
        head = NULL;
        List_Size = 0;
    }

    void Add_End(int val)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            Node *current = head;
            while (current->nextnode != NULL)
            {
                current = current->nextnode;
            }
            current->nextnode = newnode;
        }
        List_Size++;
    }

    void Print(Node *h)
    {
        if (h == NULL)
            return;

        cout << h->data << " ";
        Print(h->nextnode);
    }

    void Print()
    {
        Print(head);
        cout << endl;
    }

    Node* findMiddleRecursive(Node* slow, Node* fast)
    {
        if (fast == NULL || fast->nextnode == NULL)
        {
            return slow; 
        }

        return findMiddleRecursive(slow->nextnode, fast->nextnode->nextnode);
    }

    // Function to start the recursive middle search
    void Find_Middle()
    {
        if (head == NULL)
        {
            cout << "The list is empty." << endl;
            return;
        }
        
        Node* middle = findMiddleRecursive(head, head);  // Start with head for both slow and fast pointers
        
        if (middle != NULL)
        {
            cout << "Middle node value: " << middle->data << endl;
        }
    }
};

int main()
{
    LinkedList L1;
    L1.Add_End(1);
    L1.Add_End(2);
    L1.Add_End(3);
    L1.Add_End(4);
    L1.Add_End(5);

    cout << "Original List: ";
    L1.Print();

    L1.Find_Middle();  // Output: Middle node value: 3

    return 0;
}
