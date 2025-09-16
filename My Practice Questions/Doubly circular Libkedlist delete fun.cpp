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

            // Case 1: Empty list
            if (head == NULL)
            {
                head = newnode;
                newnode->next = newnode; // Circular reference to itself (next)
                newnode->prev = newnode; // Circular reference to itself (prev)
            }
            else if(pos == 1) // Case 2: Insertion at the beginning
            {
                current = head;
                while(current->next != head) // Traverse to the last node
                {
                    current = current->next;
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
                    current = current->next;
                }
                newnode->next = current->next;
                newnode->prev = current;
                current->next->prev = newnode;
                current->next = newnode;
            }
            List_size++; // Increment list size
        }

        void Delete_DCLL(int pos)
        {
            if (head == NULL || pos < 1 || pos > List_size)
            {
                cout << "Invalid position or list is empty!" << endl;
                return;
            }

            Node *temp;

            // Case 1: Deleting the head node
            if (pos == 1)
            {
                temp = head;
                
                if (List_size == 1) // Only one node in the list
                {
                    head = NULL;
                }
                else
                {
                    current = head;
                    while(current->next != head) // Traverse to the last node
                    {
                        current = current->next;
                    }
                    current->next = head->next;
                    head->next->prev = current;
                    head = head->next; // Update head
                }

                delete temp; // Free memory
            }
            else // Case 2: Deleting a node other than the head
            {
                current = head;
                
                for(int i = 1; i < pos - 1; i++) // Traverse to the (pos-1) node
                {
                    current = current->next;
                }

                temp = current->next; // Node to be deleted
                current->next = temp->next;
                temp->next->prev = current;

                delete temp; // Free memory
            }

            List_size--; // Decrease the size of the list
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
                current = current->next;
            } 
            while(current != head); 
			 
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

    cout << "List after adding elements: " << endl;
    L1.Print();

    // Deleting elements from different positions
    L1.Delete_DCLL(1); // Deleting head node
    cout << "List after deleting node at position 1: " << endl;
    L1.Print();

    L1.Delete_DCLL(2); // Deleting node at position 2
    cout << "List after deleting node at position 2: " << endl;
    L1.Print();
}
