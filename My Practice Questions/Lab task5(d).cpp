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

        // Function to print the list
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

        // Function to delete the first node
        void Delete_Start() 
		{
            if (head == NULL) 
			{
                cout << "List is empty!" << endl;
                return;
            }

            Node *temp = head;
            head = head->next;

            if (head != NULL)
                head->previous = NULL;

            delete temp;
            List_size--;
        }

        // Function to delete the last node
        void Delete_Last() 
		{
            if (head == NULL) 
			{
                cout << "List is empty!" << endl;
                return;
            }

            if (head->next == NULL) 
			{
                delete head;
                head = NULL;
            } 
			else 
			{
                Node *temp = head;
                current = head;
                
                while (current->next != NULL) 
				{
                    current = current->next;
                }
                
                current->previous->next = NULL;
                delete current;
            }

            List_size--;
        }

        // Function to search for a node by value and return both position and value
        Node* Find_Node(int value) 
		{
            current = head;
            int pos = 1;

            
            while (current != NULL) 
			{
                if (current->data == value) 
				{
                    cout << "Node found at position " << pos << " with value " << current->data << endl;
                    
                    return current;  
                }
                current = current->next;
                pos++;
            }

            cout << "Node with value not found!" << endl;
            return NULL;  // Return NULL if not found
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

    // Search for nodes by value
    D1.Find_Node(10);  
    D1.Find_Node(7);   
    D1.Find_Node(3);   

    return 0;
}
