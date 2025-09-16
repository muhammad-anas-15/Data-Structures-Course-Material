#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *nextnode;
        
        Node(int val)
        {
            data = val;
            nextnode = NULL;
        }
};

class LinkedList
{
    private:
        Node *head, *current;
        int List_Size;
    
    public:
        LinkedList()
        {
            head = current = NULL;
            List_Size = 0;
        }   
        
        void insertAtTail(int val)

            Node *newnode = new Node(val);
            
            if(head == NULL || List_Size == 0)
            {
                head = current = newnode;
                newnode = NULL;
                List_Size++;
            }
            else
            {
                current->nextnode = newnode;
                current = newnode;
                newnode = NULL;
                List_Size++;
            }
        }
        
        void Insert_at_Pos(int pos, int val)
        {
            Node *newnode = new Node(val);
            if(pos < 0 || pos > List_Size)
            {
                cout<<"Invalid Position!"<<endl;
            }
            else
            {
                current = head;
                for(int i = 0; i < pos; i++)
                {
                    current = current->nextnode;
                }
                newnode->nextnode = current->nextnode;
                current->nextnode = newnode;
                current = newnode;
                List_Size++;
            }
        }
        
        void Print()
        {
            current = head;
            while (current != NULL)
            {
                cout << current->data <<" ";
                current = current->nextnode;
            }
            cout << endl;
        }
        
    void Removenode(int val)
    {
      if (head == NULL) 
       {
         cout << "List is empty!" << endl;
         return;
       }

      Node *temp = head;

      if (head->data == val) 
      { 
         head = head->nextnode;  
         delete temp;  
         List_Size--; 
         return;
       }

    
      while (temp->nextnode != NULL && temp->nextnode->data != val)
      {
        temp = temp->nextnode;
      }

      if (temp->nextnode == NULL)
     {
        cout << "Value " << val << " not found in the list." << endl;
        return;
     }
           current = temp;  
       temp = temp->nextnode;  
       current->nextnode = temp->nextnode;  
       delete temp; 
       List_Size--;  
     }
     
};

int main()
{
    LinkedList L1;
    L1.insertAtTail(1);
    L1.insertAtTail(3);
    L1.insertAtTail(5);
    L1.insertAtTail(7);
    
    cout<<"\n";
    L1.Print();
    
    L1.Removenode(3);
    L1.Print();

}
