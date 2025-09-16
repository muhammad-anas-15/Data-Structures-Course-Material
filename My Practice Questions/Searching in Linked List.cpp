#include <iostream>
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
    int List_size;

public:
    LinkedList()
    {
        head = current = NULL;
        List_size = 0;
    }
    void Add_last(int val)
    {
        Node *newnode = new Node(val);

        if (head == NULL || List_size == 0)
        {
            head = current = newnode;
            head->nextnode = NULL;
            List_size++;
        }
        else
        {
            current->nextnode = newnode;
            current = newnode;
            newnode = NULL;
            List_size++;
        }
    }

    void Remove_last()
    {
        Node *temp = head;

        for (int i = 0; i < List_size - 1; i++)
        {
            temp = temp->nextnode;
        }
        current = temp;
        temp = temp->nextnode;

        delete temp;

        List_size--;
    }

    void Remove_first()
    {
        Node *temp = head;

        temp = current = head;

        head = head->nextnode;
        current = head;
        delete temp;
        List_size--;
    }

    void Remove_Pos(int pos)
    {
        Node *temp = head;

        for (int i = 1; i < pos; i++)
        {
            temp = temp->nextnode;
        }

        current = temp;
        temp = temp->nextnode;

        current->nextnode = temp->nextnode;
        delete temp;
        List_size--;
    }

    void Remove_at(int pos)
    {
        if (pos < 0 || pos >= List_size) // if the position is valid
        {
            return;
        }

        if (pos == 0) // removal of the first node
        {
            Node *temp = head;
            head = head->nextnode;
            delete temp;
        }

        else if (pos == List_size - 1) // Removal of the last node
        {
            Node *temp = head;
            for (int i = 0; i < List_size - 2; i++)
            {
                temp = temp->nextnode;
            }
            current = temp;
            temp = temp->nextnode;
            delete temp;
            current->nextnode = NULL;
        }

        else // removal of any other node
        {
            Node *temp = head;
            for (int i = 1; i < pos; i++)
            {
                temp = temp->nextnode;
            }
            current = temp;
            temp = temp->nextnode;
            current->nextnode = temp->nextnode;
            delete temp;
            List_size--;
        }
    }
    

    int Search(int val) // Function to search for a value
    {
        Node *temp = head;
        int pos = 0;

        while (temp != NULL)
        {
            if (temp->data == val)
            {
                return pos; // Return the position if the value is found
            }
            temp = temp->nextnode;
            pos++;
        }
        return -1; // Return -1 if the value is not found
    }

    int Searchbyposition(int pos) // Function to search for a value
    {
        Node *temp = head;
        int val = 0;
        
        for(int i=1; i<pos ; i++)
        {
        	temp = temp->nextnode ;
		}
        temp = temp->nextnode ;
        return temp->data ; // Return -1 if the value is not found
    }

    void Print()
    {
        current = head;

        for (int i = 0; i < List_size; i++)
        {
            cout << current->data << " ";
            current = current->nextnode;
        }
    }
};

int main()
{
    LinkedList L1;
    L1.Add_last(3);
    L1.Add_last(5);
    L1.Add_last(7);
    L1.Add_last(9);
    L1.Print();

    int searchValue = 7;
    int position = L1.Search(searchValue);
    
    cout<<"\n";
    
    cout<<"Value at Position 2 is: "<<L1.Searchbyposition(2);
    
    cout<<"\n\n";
    
    if (position != -1)
    {
        cout << "Value " << searchValue << " found at position: " << position << endl;
    }
    else
    {
        cout << "Value " << searchValue << " not found in the list." << endl;
    }

    return 0;
}
