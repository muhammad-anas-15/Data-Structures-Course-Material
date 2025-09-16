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

            if(head == NULL) 
            {
                head = newnode;
                newnode->nextnode = head; 
            }
            else if(pos == 1) 
            {
                newnode->nextnode = head;
                current = head;
                
                while(current->nextnode != head)
                {
                    current = current->nextnode;
                }
                current->nextnode = newnode;
                head = newnode;
            }
            else 
            {
                current = head;
                for(int i = 1; i < pos - 1; i++)
                {
                    current = current->nextnode;
                }
                newnode->nextnode = current->nextnode;
                current->nextnode = newnode;
            }
            List_size++;
        }

void Delete_odd_nodes() 
{
    if (head == NULL) 
    {
        cout << "List Empty!" << endl;
        return;
    }

    if (head->nextnode == head) 
    {
        delete head;
        head = NULL;
        List_size--;
        return;
    }

    Node* temp = head;
    current = head;

    while (current->nextnode != head) 
    {
        current = current->nextnode;
    }
    
    // 1, 2, 3, 4, 5
    
    head = head->nextnode;
    current->nextnode = head;
    delete temp; // 2, 3 , 4 , 5
    List_size--;

    temp = head;

    while (temp->nextnode != head)
    {
        Node* node_to_delete = temp->nextnode;
        
        if (node_to_delete->nextnode == head)
        {
            temp->nextnode = head;
            delete node_to_delete;
            List_size--;
            break;
        }

        temp->nextnode = node_to_delete->nextnode;
        delete node_to_delete;
        List_size--;

        temp = temp->nextnode;
    }
    
    current = head;
    while (current->nextnode != head) 
    {
        current = current->nextnode;
    }
    current->nextnode = head;
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
            while(current != head); 
			 
            cout << endl;
        }
};

int main()
{
    LinkedList L1;
    L1.Add_CLL(1, 1);
    L1.Add_CLL(2, 2);
    L1.Add_CLL(3, 3);
    L1.Add_CLL(4, 4);
    L1.Add_CLL(5, 5);

    cout << "List after adding elements: " << endl;
    L1.Print();

   
    L1.Delete_odd_nodes(); 
    cout << "List after deleting: " << endl;
    L1.Print();
}
