#include <iostream>
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

    void Find_Middle()
    {
        if (head == NULL)
        {
            cout << "The list is empty." << endl;
            return;
        }

        Node *slow = head; 
        Node *fast = head; 

        while (fast != NULL && fast->nextnode != NULL)
        {
            slow = slow->nextnode;          
            fast = fast->nextnode->nextnode; 
        }

        cout << "Middle node value: " << slow->data << endl;
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

    L1.Find_Middle(); // Output: Middle node value: 3

    return 0;
}
