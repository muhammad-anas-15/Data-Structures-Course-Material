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
        
        int countNodes(Node *h)
         {
           if (h == NULL)
              return 0; 

           return 1 + countNodes(h->nextnode); // Add 1 for the current node and recurse
         }

       void Count()
      {
         cout << "No of nodes are: " << countNodes(head) << endl;
      }

        void Print()
        {
            Print(head);
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
    L1.Print();
    cout << "\n\n";
    L1.Add_Post(2, 10);
    L1.Print();
    cout<<"\n\n";
    L1.Count();
}
