#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *previous;

    Node(int val)
    {
        data = val;
        next = previous = NULL;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    int List_Size;

public:
    DoublyLinkedList()
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
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newnode;
            newnode->previous = current;
        }
        List_Size++;
    }

    void Print(Node *h)
    {
        if (h == NULL)
            return;

        cout << h->data << " ";
        Print(h->next);
    }

    void Print()
    {
        Print(head);
        cout << endl;
    }

    Node* findMiddleRecursive(Node* slow, Node* fast)
    {
        if (fast == NULL || fast->next == NULL)
        {
            return slow; 
        }

        
        return findMiddleRecursive(slow->next, fast->next->next);
    }

    void Find_Middle()
    {
        if (head == NULL)
        {
            cout << "The list is empty." << endl;
            return;
        }
        
        Node* middle = findMiddleRecursive(head, head);  
        
        if (middle != NULL)
        {
            cout << "Middle node value: " << middle->data << endl;
        }
    }
};

int main()
{
    DoublyLinkedList D1;
    D1.Add_End(1);
    D1.Add_End(2);
    D1.Add_End(3);
    D1.Add_End(4);
    D1.Add_End(5);

    cout << "Original List: ";
    D1.Print();

    D1.Find_Middle();  // Output: Middle node value: 3

    return 0;
}
