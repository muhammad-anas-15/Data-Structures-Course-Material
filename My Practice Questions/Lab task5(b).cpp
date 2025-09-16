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
            while(current != NULL)  
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;  
        }

        void Add_Start(int val)
        {
            Node *newnode = new Node(val);

            if (head == NULL)  
            {
                head = newnode;
            }
            else
            {
                newnode->next = head;
                head->previous = newnode;
                head = newnode;
            }
            List_size++;
        }   

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

                while (current->next != NULL)
                {
                    current = current->next;
                }

                current->next = newnode;
                newnode->previous = current;
            }

            List_size++;  
        }

        void Add_pos(int pos, int val)
        {

            if (pos < 1 || pos > List_size + 1)
            {
                cout << "Invalid position!" << endl;
                return;
            }

            Node *newnode = new Node(val);

            if (pos == 1)
            {
                Add_Start(val);
            }

            else
            {
                current = head;
                int count = 1;

                while (count < pos - 1 && current != NULL)
                {
                    current = current->next;
                    count++;
                }

                if (current->next == NULL)
                {
                    Add_Last(val);
                }

                else
                {
                    newnode->next = current->next;
                    newnode->previous = current;
                    current->next->previous = newnode;
                    current->next = newnode;
                }
            }

            List_size++; 
        }

    void Reverse_Doubly_LL()
   {
    Node *previous = NULL;
    Node *forward = NULL;
    
    current = head;
    
    while (current != NULL)
    {
        forward = current->next;  // Store the next node

        
        current->next = current->previous;
        current->previous = forward;

        
        previous = current;
        current = forward;
    }

    
    head = previous;// After reversing, set head to the last processed node
}



};

int main()
{
    Doubly_LinkedList D1;
    D1.Add_Start(4);
    D1.Add_Start(5);
    D1.Add_Start(6);
    
    // Before reversal: 6 5 4
    cout<<"Before reversal linked list is: "<<endl;
    D1.Print();            
    D1.Reverse_Doubly_LL();
    
    // After reversal: 4 5 6
    cout<<"\nAfter reversal linked list is: "<<endl;
    D1.Print();            
}
