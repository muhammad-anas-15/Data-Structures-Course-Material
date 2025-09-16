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

            // Case 1: If the list is empty
            if(head == NULL)
            {
                head = newnode;
                newnode->nextnode = head; // Circular reference to itself
            }
            else if(pos == 1) // Case 2: Insertion at the beginning
            {
                newnode->nextnode = head;
                current = head;
                
                while(current->nextnode != head) // Traverse to the last node
                {
                    current = current->nextnode;
                }
                current->nextnode = newnode; // Last node points to the new head
                head = newnode; // Update head
            }
            else // Case 3: Insertion at a position other than the first
            {
                current = head;
                
                for(int i = 1; i < pos - 1; i++) // Traverse to the (pos-1) node
                {
                    current = current->nextnode;
                }
                newnode->nextnode = current->nextnode; // Set new node's next to the current node's next
                current->nextnode = newnode; // Link current node to the new node
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
    
	void Reverse() 
	{
       if (head == NULL) return; // Handle empty list

    Node *current = head;
    Node *previous = NULL;
    Node *next = NULL;

    do 
	{
        next = current->nextnode; 
        current->nextnode = previous; 
        previous = current; 
        current = next;
    } 
    
	while (current != head); 

    head->nextnode = previous; 
    head = previous;
}

        
};

int main()
{
    LinkedList L1;
    L1.Add_CLL(1, 5);
    L1.Add_CLL(2, 2);
    L1.Add_CLL(3, 7);
    L1.Add_CLL(4, 0);
    L1.Print();
    L1.Reverse();
    L1.Print();
}
