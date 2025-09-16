#include<iostream>
using namespace std;

class Node 
{
    public:
        int data;
        Node *next, *previous;

        Node(int d) 
		{
            this->data = d;
            next = previous = NULL;
        }
};

class Doubly_LinkedList 
{
    private:
        Node *head, *current;
        int List_size;

    public:
        Doubly_LinkedList() 
		{
            head = current = NULL;
            List_size = 0;
        }

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

        void Add_Start(int value) 
		{
            Node *newNode = new Node(value);
            if (head == NULL) 
			{
                head = newNode;
            } 
			else 
			{
                newNode->next = head;
                head->previous = newNode;
                head = newNode;
            }
            List_size++;
        }

        void Add_Last(int value) 
		{
            Node *newNode = new Node(value);
            if (head == NULL) 
			{
                head = newNode;
            } 
			else 
			{
                current = head;
                while (current->next != NULL) 
				{
                    current = current->next;
                }
                current->next = newNode;
                newNode->previous = current;
            }
            List_size++;
        }

        
        void Add_pos(int pos, int value) 
		{
        	
            if (pos < 1 || pos > List_size + 1) 
			{
                cout << "Invalid position!" << endl;
                return;
            }

            if (pos == 1) 
			{
                Add_Start(value);
            } 
			else if (pos == List_size + 1) 
			{
                Add_Last(value);
            } 
			else 
			{
                Node *newNode = new Node(value);
                current = head;
                int count = 1;
                while (count < pos - 1) 
				{
                    current = current->next;
                    count++;
                }
                
                newNode->next = current->next;
                newNode->previous = current;
                
                if (current->next != NULL) 
				{
                    current->next->previous = newNode;
                }
                current->next = newNode;
                List_size++;
            }
        }

        int Count_Nodes() 
		{
            return List_size;  // Return the list size
        }
};

int main() {
    Doubly_LinkedList D1;
    
    // Add elements to the list
    D1.Add_Start(4);
    D1.Add_Start(5);
    D1.Add_Start(6);
    D1.Print();

    D1.Add_Last(7);
    D1.Print();

    D1.Add_pos(2, 10);
    D1.Print();

    // Count the number of nodes
    cout << "Total nodes: " << D1.Count_Nodes() << endl;

    return 0;
}
