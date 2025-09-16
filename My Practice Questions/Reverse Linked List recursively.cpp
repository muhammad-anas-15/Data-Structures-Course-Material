#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *nextnode;

        Node(int val)  // Constructor to initialize the node with a value
        {
            data = val;
            nextnode = NULL;
        }
};

class LinkedList
{
    private:
        Node *head;

    public:
        LinkedList()
        {
            head = NULL;  // Initialize the head to NULL
        }

        ~LinkedList()  // Destructor to free the memory of nodes
        {
            Node *temp;
            while (head != NULL)
            {
                temp = head;
                head = head->nextnode;
                delete temp;
            }
        }

        // Function to add a new node at the end of the list
        void Add_End(int val)
        {
            Node *newnode = new Node(val);

            if (head == NULL)
            {
                head = newnode;  // If the list is empty, set the new node as the head
            }
            else
            {
                Node *current = head;
                while (current->nextnode != NULL)
                {
                    current = current->nextnode;
                }
                current->nextnode = newnode;  // Link the new node at the end
            }
        }

        // Function to add a new node at the start of the list
        void Add_Start(int val)
        {
            Node *newnode = new Node(val);
            newnode->nextnode = head;  // Point the new node to the current head
            head = newnode;  // Set the new node as the new head
        }

        // Function to add a new node at a specific position in the list
        void Add_Post(int pos, int val)
        {
            if (pos < 0)
            {
                cout << "Invalid Position!" << endl;
                return;
            }

            if (pos == 0)
            {
                Add_Start(val);  // If position is 0, add at the start
                return;
            }

            Node *newnode = new Node(val);
            Node *current = head;

            for (int i = 0; i < pos - 1 && current != NULL; i++)
            {
                current = current->nextnode;
            }

            if (current == NULL)
            {
                cout << "Position out of bounds!" << endl;
                return;
            }

            newnode->nextnode = current->nextnode;
            current->nextnode = newnode;
        }


        Node* Reverse_Recursive(Node *current)  
        {
            if (current == NULL || current->nextnode == NULL)
            {
                return current; 
            }

            Node *newHead = Reverse_Recursive(current->nextnode);


            current->nextnode->nextnode = current;
            current->nextnode = NULL;

            return newHead; 
        }

        void Reverse()
        {
            head=Reverse_Recursive(head);
        }


        void Print(Node *h)
        {
            if (h != NULL)
            {
                cout << h->data << " ";  
                Print(h->nextnode);     
            }
        }

        void Print()
        {
            Print(head);
            cout << endl;
        }
};

int main()
{
    LinkedList L1;

    // Adding nodes to the list
    L1.Add_End(5);
    L1.Add_End(6);
    L1.Add_End(2);
    L1.Add_End(0);

    // Print the original list
    cout << "Original List: ";
    L1.Print();

    // Adding node at the start
    L1.Add_Start(3);
    cout << "After Adding at Start: ";
    L1.Print();

    // Adding node at position 2
    L1.Add_Post(2, 10);
    cout << "After Adding at Position 2: ";
    L1.Print();

    // Reversing the list
    L1.Reverse();
    cout << "Reversed List: ";
    L1.Print();

    return 0;
}
