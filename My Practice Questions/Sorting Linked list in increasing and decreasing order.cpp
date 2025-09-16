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

        ~LinkedList()
        {
            Node *temp;
            while (head != NULL)
            {
                temp = head;
                head = head->nextnode;
                delete temp;
            }
        }

        void Add_End(int val)
        {
            Node *newnode = new Node(val);

            if (head == NULL)
            {
                head = current = newnode;
            }
            else
            {
                current->nextnode = newnode;
                current = newnode;
            }
            List_Size++;
        }

        void Add_Start(int val)
        {
            Node *newnode = new Node(val);
            newnode->nextnode = head;
            head = newnode;

            if (List_Size == 0) // If this is the first node, set current to head
                current = head;

            List_Size++;
        }

        void Add_Post(int pos, int val)
        {
            if (pos < 0 || pos > List_Size)
            {
                cout << "Invalid Position!" << endl;
                return;
            }

            Node *newnode = new Node(val);

            if (pos == 0) // Adding at the start
            {
                Add_Start(val);
            }
            else
            {
                current = head;
                for (int i = 0; i < pos - 1; i++)
                {
                    current = current->nextnode;
                }
                newnode->nextnode = current->nextnode;
                current->nextnode = newnode;
                List_Size++;
            }
        }

        void Print(Node *h)
        {
            if (h == NULL)
                return;

            cout << h->data << " ";
            Print(h->nextnode);
        }

        void Print()
        {
            Print(head);
        }

        void Sort_Increasing()
        {
            if (head == NULL) return;

            current = head;

        while (current != NULL)
        {
             Node *temp = head;  // Reset temp to head for each outer iteration
           
          while (temp->nextnode != NULL)  // Ensure we don't go out of bounds
         {
            if (temp->data > temp->nextnode->data)
            {
                swap(temp->data, temp->nextnode->data);
            }
                temp = temp->nextnode;
         }
              current = current->nextnode;
        }
       }


        void Sort_Decreasing()
        {
           if (head == NULL) return;

           current = head;

        while (current != NULL)
        {
            Node *temp = head;  // Reset temp to head for each outer iteration
            
        while (temp->nextnode != NULL)  // Ensure we don't go out of bounds
        {
            if (temp->data < temp->nextnode->data)
            {
                swap(temp->data, temp->nextnode->data);
            }
            temp = temp->nextnode;
        }
        current = current->nextnode;
    }
}

};

int main()
{
    LinkedList L1;
    L1.Add_End(5);
    L1.Add_End(6);
    L1.Add_End(2);
    L1.Add_End(0);
    L1.Add_Start(3);

    cout << "Original List: ";
    L1.Print();
    cout << "\n\n";

    L1.Sort_Increasing();
    cout << "Sorted in Increasing Order: ";
    L1.Print();
    cout << "\n\n";

    L1.Sort_Decreasing();
    cout << "Sorted in Decreasing Order: ";
    L1.Print();
    cout << "\n";

    return 0;
}
