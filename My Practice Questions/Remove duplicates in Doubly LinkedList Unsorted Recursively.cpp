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

        Node* Delete_Duplicates_Recursive(Node* h1)
        {
            if (h1 == NULL || h1->next == NULL)
            
                return h1;
                
            h1->next = Delete_Duplicates_Recursive(h1->next);

           
            if (h1->data == h1->next->data)
            {
                Node* todelete = h1->next;  
                
                h1->next = h1->next->next;  

                if (h1->next != NULL)
                {
                    h1->next->previous = h1;  
                }

                delete todelete;  
                List_size--;
            }

            return h1;
        }

        void Delete_Duplicates()
        {
            head = Delete_Duplicates_Recursive(head);
        }
};

int main()
{
    Doubly_LinkedList D1;
    
    // Adding some elements to the list
    D1.Add_Start(6);
    D1.Add_Start(5);
    D1.Add_Start(4);
    D1.Add_Start(4); // Duplicate
    D1.Add_Start(2);
    
    cout << "List before removing duplicates: " << endl;
    D1.Print();

    // Call the function to remove duplicates in an unsorted list
    D1.Delete_Duplicates();

    cout << "List after removing duplicates: " << endl;
    D1.Print();

    return 0;
}
