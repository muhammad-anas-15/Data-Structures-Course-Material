#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int d)
        {
            data = d;
            next = prev = NULL;
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

        void Add_DCLL(int pos, int val)
        {
            if (pos < 1 || pos > List_size + 1)
            {
                cout << "Invalid position!" << endl;
                return;
            }

            Node *newnode = new Node(val);

            
            if(head == NULL)
            {
                head = newnode;
                newnode->next = head; 
                newnode->prev = head; 
            }
            else if(pos == 1) 
            {
                current = head;
                
                while(current->next != head) 
                {
                    current = current->next;
                }
                newnode->next = head;
                newnode->prev = current;
                
                head->prev = newnode;
                current->next = newnode;
                
                head = newnode; 
            }
            else 
            {
                current = head;
                for(int i = 1; i < pos - 1; i++) 
                {
                    current = current->next;
                }
                newnode->next = current->next;
                newnode->prev = current;
                
                current->next->prev = newnode;
                current->next = newnode;
            }
            List_size++; 
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
                current = current->next;
            } 
            while(current != head); 
			 
            cout << endl;
        }

        void Reverse() 
        {
            if (head == NULL) return; 

            Node* current = head;
            Node* previous = NULL;
            Node* next = NULL;

           
            do 
            {
                next = current->next;       
                current->next = previous;     
                current->prev = next;         
                previous = current;          
                current = next;
            } 
            
            while (current != head);

           
            head->next = previous;           
            head->prev = current;             
            head = previous;                  
        }
};

int main()
{
    LinkedList L1;
    L1.Add_DCLL(1, 1);
    L1.Add_DCLL(2, 2);
    L1.Add_DCLL(3, 3);
    L1.Add_DCLL(4, 4);
    
    cout << "Original List: ";
    L1.Print();

    L1.Reverse();
    cout << "Reversed List: ";
    L1.Print();

    return 0;
}
