#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *nextnode;

        Node(int d)
        {
            data = d;
            nextnode = NULL;
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

        void Add_CLL(int pos, int val)
        {
            if (pos < 1 || pos > List_size + 1)
            {
                cout << "Invalid position!" << endl;
                return;
            }

            Node *newnode = new Node(val);

            if(head == NULL) // Case 1: Empty list
            {
                head = newnode;
                newnode->nextnode = head;
            }
            else if(pos == 1) // Case 2: Insertion at the beginning
            {
                newnode->nextnode = head;
                current = head;
                
                while(current->nextnode != head)
                {
                    current = current->nextnode;
                }
                current->nextnode = newnode;
                head = newnode;
            }
            else // Case 3: Insertion at a position other than the first
            {
                current = head;
                for(int i = 1; i < pos - 1; i++)
                {
                    current = current->nextnode;
                }
                newnode->nextnode = current->nextnode;
                current->nextnode = newnode;
            }
            List_size++;
        }

        void Delete_CLL(int pos)
        {
            if (head == NULL || pos < 1 || pos > List_size)
            {
                cout << "Invalid position or list is empty!" << endl;
                return;
            }

            Node *temp; // Using temp pointer for deletion

            // Case 1: Deleting the head node
            if (pos == 1)
            {
                temp = head;
                current = head;
                
                if (List_size == 1) // If there's only one node in the list
                {
                    head = NULL;
                }
                else
                {
                    while(current->nextnode != head) // Find the last node
                    {
                        current = current->nextnode;
                    }
                    current->nextnode = head->nextnode; // Last node points to the second node
                    head = head->nextnode; // Update head
                }

                delete temp; // Free memory
            }
            else // Case 2: Deleting a node other than the head
            {
                current = head;

                // Traverse to the node before the node to be deleted
                for(int i = 1; i < pos - 1; i++)
                {
                    current = current->nextnode;
                }

                temp = current->nextnode; // Temp points to the node to be deleted
                current->nextnode = temp->nextnode; // Bypass the node to be deleted
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
                current = current->nextnode;
            } 
            while(current != head); 
			 
            cout << endl;
        }
};

int main()
{
    LinkedList L1;
    L1.Add_CLL(1, 5);
    L1.Add_CLL(2, 2);
    L1.Add_CLL(3, 7);
    L1.Add_CLL(4, 0);

    cout << "List after adding elements: " << endl;
    L1.Print();

    // Deleting elements from different positions
    L1.Delete_CLL(1); // Deleting head node
    cout << "List after deleting node at position 1: " << endl;
    L1.Print();

    L1.Delete_CLL(2); // Deleting node at position 2
    cout << "List after deleting node at position 2: " << endl;
    L1.Print();
}
