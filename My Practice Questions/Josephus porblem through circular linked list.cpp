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
        Node *head;
        int List_size;

    public:
        LinkedList()
        {
            head = NULL;
            List_size = 0;
        }

        // Add a node at the end of the circular linked list
        void Add_CLL(int val)
        {
            Node *newnode = new Node(val);

            // Case 1: If the list is empty
            if(head == NULL)
            {
                head = newnode;
                newnode->nextnode = head; // Circular reference to itself
            }
            else // Case 2: Adding a node at the end
            {
                Node *current = head;
                
                while(current->nextnode != head) // Traverse to the last node
                {
                    current = current->nextnode;
                }
                current->nextnode = newnode; // Link last node to the new node
                newnode->nextnode = head; // Circular reference to head
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

            Node *current = head;
            do
            {
                cout << current->data << " ";
                current = current->nextnode;
            } 
            while(current != head); // Traverse the circular list until we reach the head again
			 
            cout << endl;
        }

        // Function to solve Josephus Problem
        void Josephus(int k)
        {
            Node *current = head;
            Node *prev = NULL;

            // If the list is empty, return
            if(head == NULL)
                return;

            // Continue until only one node is left
            while(List_size > 1)
            {
                // Move to the k-th node
                for(int count = 1; count < k; count++)
                {
                    prev = current; // Keep track of the previous node
                    current = current->nextnode;
                }

                // Delete the k-th node (current node)
                cout << "Person " << current->data << " is eliminated." << endl;
                
                prev->nextnode = current->nextnode; // Link previous node to the next node
                if(current == head) // If the head is being removed, move the head pointer
                    head = current->nextnode;

                delete current; // Free memory of the eliminated node
                current = prev->nextnode; // Move to the next node

                List_size--; // Decrease the size of the list
            }

            cout << "The survivor is person " << head->data << endl;
        }
};

int main()
{
    LinkedList L1;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    // Create the circular linked list with 7 people
    for(int i = 0; i < size; i++)
    {
        L1.Add_CLL(arr[i]);
    }

    // Print the initial circle
    cout << "Initial circle: ";
    L1.Print();

    // Solve the Josephus problem
    L1.Josephus(k);

    return 0;
}
