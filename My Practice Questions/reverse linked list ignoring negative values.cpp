#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* nextnode;

    Node(int val) 
	{
        data = val;
        nextnode = NULL;
    }
};

class LinkedList 
{
private:
    Node* head;
    Node* current;
    int List_Size;

public:
    LinkedList() 
	{
        head = current = NULL;
        List_Size = 0;
    }

    void Add_End(int val) 
	{
        Node* newnode = new Node(val);

        if (head == NULL) 
		{
            head = current = newnode;
        } 
		else 
		{
            current->nextnode = newnode;
            current = newnode;
        }
        List_Size++;
    }

    void Print() 
	{
        current = head;
        
        for (int i = 0; i < List_Size; i++) 
		{
            cout << current->data << " ";
            current = current->nextnode;
        }
    }

    void Reverse() 
	{
        Node* previous = NULL;
        Node* current = head;
        Node* forward = NULL;

        // Use a temporary linked list for the reversed positive nodes
        LinkedList reversedPositives;
        
        Node* negativeHead = NULL; // Head for negative nodes
        Node* negativeTail = NULL; // Tail for negative nodes

        // Separate positive and negative nodes
        while (current != NULL) 
		{
            forward = current->nextnode;

            if (current->data < 0) 
			{
                // Keep track of negative nodes
                if (negativeHead == NULL) 
				{
                    negativeHead = current;
                    negativeTail = current;
                } 
				else 
				{
                    negativeTail->nextnode = current;
                    negativeTail = current;
                }
                negativeTail->nextnode = NULL; // End the negative list
            } 
			else 
			{
                // Add positive nodes to the reversed list
                current->nextnode = previous; // Reverse
                previous = current;
            }

            current = forward;
        }

        // Construct the new list
        head = previous; // Start with reversed positive nodes

        // If there are negative nodes, connect them
        if (head != NULL && negativeHead != NULL) 
		{
            Node* temp = head;
            
            while (temp->nextnode != NULL) 
			{
                temp = temp->nextnode; // Traverse to the end of positive nodes
            }
            
            temp->nextnode = negativeHead; // Connect negative nodes
        } 
		else if (negativeHead != NULL) 
		{
            head = negativeHead; // If only negative nodes exist
        }
    }
};

int main() 
{
    LinkedList L1;
    L1.Add_End(1);
    L1.Add_End(2);
    L1.Add_End(-3);
    L1.Add_End(-4);
    L1.Add_End(5);
    L1.Add_End(6);

    cout << "Original list: ";
    L1.Print();
    cout << "\n\n";

    L1.Reverse();

    cout << "Reversed list: ";
    L1.Print();  // Should print 6 5 -3 -4 2 1
}
