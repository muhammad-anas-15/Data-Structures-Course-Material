#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;

        Node(int d)
        {
            this->data = d;
            next = NULL;
        }
};

class Singly_LinkedList
{
    private:
        Node *head, *current;

    public:
        Singly_LinkedList()
        {
            head = current = NULL;
        }

        // Add node at the end of the list
        void Add_Last(int val)
        {
            Node *newnode = new Node(val);

            if (head == NULL)
            {
                head = newnode;
            }
            else
            {
                current = head;

                // Traverse to the end of the list
                while (current->next != NULL)
                {
                    current = current->next;
                }

                current->next = newnode;
            }
        }

        // Function to detect a loop in the linked list and count the nodes in the loop
        int FindLengthofcycle()
        {
            Node *temp1 = head, *temp2 = head;

            // Step 1: Detect the loop
            while (temp2 != NULL && temp2->next != NULL)
            {
                temp1 = temp1->next;
                temp2 = temp2->next->next;

                if (temp1 == temp2)  // Loop detected
                {
                    // Step 2: Count the number of nodes in the loop
                    int count = 1;  // Start from 1 since temp1 and temp2 have already met
                    Node *current = temp1;

                    while (current->next != temp1)  // Traverse the cycle
                    {
                        current = current->next;
                        count++;
                    }
                    return count;  // Return the length of the cycle
                }
            }

            // No loop found
            return 0;
        }

        // Print the list (for testing purposes)
        void Print()
        {
            current = head;
            while (current != NULL)
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
};

int main()
{
    Singly_LinkedList L1;

    // Adding nodes to the list
    L1.Add_Last(1);
    L1.Add_Last(2);
    L1.Add_Last(3);
    L1.Add_Last(4);
    L1.Add_Last(5);

    // Creating a loop for testing
    L1.head->next->next->next->next->next = L1.head->next->next; // Making node 5 point to node 3

    // Detecting the loop and counting nodes in the cycle
    int cycleLength = L1.FindLengthofcycle();
    
    if (cycleLength > 0)
    {
        cout << "Loop detected with length: " << cycleLength << endl;
    }
    else
    {
        cout << "No loop detected in the list." << endl;
    }

    return 0;
}
