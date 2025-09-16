#include<iostream>
using namespace std;

class Node 
{
    public:
        int data;
        Node *next, *previous;

        Node(int d) {
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

        
        void Add_Start(int value) // Function to add a node at the start
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

        
        void Add_Last(int value) // Function to add a node at the end
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

        
        void Add_pos(int pos, int value) // Function to add a node at a specific position
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

        
        void Delete_Start() // Function to delete the first node
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

        
        void Delete_Last() // Function to delete the last node
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

        
        void Delete_pos(int value) // Function to delete a node by value
		{
            int pos = Search_Position(value);  // Find the position of the value

            if (pos == -1) 
			{
                cout << "Value " << value << " not found in the list!" << endl;
                return;
            }

            if (pos == 1) 
			{
                Delete_Start();
            } 
			else if (pos == List_size)
			{
                Delete_Last();
            } 
			else 
			{
                current = head;
                int count = 1;

                
                while (count < pos) // Traverse to the position to delete the node
				{
                    current = current->next;
                    count++;
                }

                Node *temp = current;
                
                temp->previous->next = temp->next;
                temp->next->previous = temp->previous;

                delete temp;
                List_size--;
            }

            cout << "Value " << value << " deleted from the list!" << endl;
        }

        
        int Search_Position(int value) // Function to search for a value and return its position
		{
            current = head;  // Start from the head
            
            int pos = 1;     // Position counter starts at 1

            while (current != NULL) 
			{
                if (current->data == value) 
				{
                    return pos;  
                }
                current = current->next;
                pos++;
            }

            return -1;  // if value is not found
        }
};

int main() 
{
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

    // Delete elements from the list
    D1.Delete_Start();
    D1.Print();

    D1.Delete_Last();
    D1.Print();

    D1.Delete_pos(10);  // Delete by value using Search_Position
    D1.Print();

    return 0;
}
