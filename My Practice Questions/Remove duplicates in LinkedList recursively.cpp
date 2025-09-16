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
            cout << endl;
        }

        
        
        Node* Delete_Duplicates_Recursive(Node* h1)
        {
            if (h1 == NULL || h1->nextnode == NULL)
            
                return h1;

            h1->nextnode = Delete_Duplicates_Recursive(h1->nextnode);

            if (h1->data == h1->nextnode->data)
            {
                Node* temp = h1->nextnode;
                h1->nextnode = h1->nextnode->nextnode;
                
                delete temp;
                List_Size--;
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
    LinkedList L1;
    L1.Add_End(5);
    L1.Add_End(6);
    L1.Add_End(6);
    L1.Add_End(2);
    L1.Add_End(2);
    L1.Add_End(0);
    L1.Add_Start(3);

    cout << "Original List: ";
    L1.Print();   // Print before removing duplicates

    L1.Delete_Duplicates();

    cout << "After Deleting Duplicates: ";
    L1.Print();   // Print after removing duplicates

    return 0;
}
