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
        {
            //first create new node.
            Node *newnode = new Node(val);
            
            if(head == NULL || List_Size == 0)
            {
                head = current = newnode;
                newnode->nextnode = NULL;
                List_Size++;
            }
            else
            {
                current->nextnode = newnode;
                current = newnode;
                newnode->nextnode = NULL;
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

};

int main()
{
    LinkedList L1;
    L1.insertAtTail(1);
    L1.insertAtTail(3);
    L1.insertAtTail(5);
    L1.insertAtTail(7);
    L1.Print();
}
