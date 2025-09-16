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

        // Function to detect a loop in the linked list
        bool Detect_Loop()
        {
            Node *slow = head, *fast = head;

            while (fast != NULL && fast->next != NULL)
            {
                slow = slow->next;         // Moves one step
                fast = fast->next->next;   // Moves two steps

                if (slow == fast)          // If slow and fast meet, there is a loop
                {
                    return true;
                }
            }

            return false; // No loop found
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
        int FindLengthofcycle(Node *head)
        {
        	Node *current = head;
        	Node *temp1, *temp2;
        	temp1 = temp2  =head;
        	int count = 1;
        	
        	while(temp1 != NULL && temp2->next != NULL)
        	{
        		temp1 = temp1->next;
        		temp2 = temp2->next->next;
        		
        		if(temp1 == temp2)
        		{
        			count++;
				}
			}
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
    //L1.head->next->next->next->next->next = L1.head->next; // Making node 5 point to node 2

    // Detecting the loop
    if (L1.Detect_Loop())
    {
        cout << "Loop detected in the list." << endl;
    }
    else
    {
        cout << "No loop detected in the list." << endl;
    }

    return 0;
}
