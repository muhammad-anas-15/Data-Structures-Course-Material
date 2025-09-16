#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int d)
        {
            data = d;
            next = prev = NULL;
        }
};

class LinkedList
{
    private:
        Node *current, *head;
        int List_size;

    public:
        LinkedList()
        {
            current = head = NULL;
            List_size = 0;
        }

        void Add_DCLL(int pos, int val)
        {
            if (pos < 1 || pos > List_size + 1)
            {
                cout << "Invalid position!" << endl;
                return;
            }

            Node *newnode = new Node(val);

            // Case 1: If the list is empty
            if(head == NULL)
            {
                head = newnode;
                newnode->next = head; // Circular reference to itself (next)
                newnode->prev = head; // Circular reference to itself (prev)
            }
            else if(pos == 1) // Case 2: Insertion at the beginning
            {
                current = head;
                while(current->nextnode != head) // Traverse to the last node
                {
                    current = current->nextnode;
                }
                newnode->next = head;
                newnode->prev = current;
                
                head->prev = newnode;
                current->next = newnode;
                
                head = newnode; // Update head
            }
            else // Case 3: Insertion at a position other than the first
            {
                current = head;
                for(int i = 1; i < pos - 1; i++) // Traverse to the (pos-1) node
                {
                    current = current->nextnode;
                }
                newnode->next = current->nextnode;
                newnode->prev = current;
                
                current->next->prev = newnode;
                current->nextnode = newnode;
            }
            List_size++; // Increment list size
        }

        void Print()
        {
            if (head == NULL)
            {
                cout << "List is empty." << endl;
                return;
            }

            current = head;
            do
            {
                cout << current->data << " ";
                current = current->nextnode;
            } 
            while(current != head); // Ensure we cover all nodes in the circular list
			 
            cout << endl;
        }
        
};

int main()
{
    LinkedList L1;
    L1.Add_DCLL(1, 5);
    L1.Add_DCLL(2, 2);
    L1.Add_DCLL(3, 7);
    L1.Add_DCLL(4, 0);
    L1.Print();
}
