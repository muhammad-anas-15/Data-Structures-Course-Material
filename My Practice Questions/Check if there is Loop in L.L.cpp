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
        Node *head;

    public:
        LinkedList()
        {
            head = NULL;  // Initialize the head to NULL
        }

        ~LinkedList()  // Destructor to free the memory of nodes
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
                head = newnode;
            }
            else
            {
                Node *current = head;
                while (current->nextnode != NULL)
                {
                    current = current->nextnode;
                }
                current->nextnode = newnode;
            }
        }

        void Add_Start(int val)
        {
            Node *newnode = new Node(val);
            newnode->nextnode = head;
            head = newnode;
        }

        void Add_Post(int pos, int val)
        {
            if (pos < 0)
            {
                cout << "Invalid Position!" << endl;
                return;
            }

            if (pos == 0)
            {
                Add_Start(val);
                return;
            }

            Node *newnode = new Node(val);
            Node *current = head;

            for (int i = 0; i < pos - 1 && current != NULL; i++)
            {
                current = current->nextnode;
            }

            if (current == NULL)
            {
                cout << "Position out of bounds!" << endl;
                return;
            }

            newnode->nextnode = current->nextnode;
            current->nextnode = newnode;
        }

        Node* Reverse_Recursive(Node *current)
        {
            if (current == NULL || current->nextnode == NULL)
            {
                return current;
            }

            Node *newHead = Reverse_Recursive(current->nextnode);

            current->nextnode->nextnode = current;
            current->nextnode = NULL;

            return newHead;
        }

        void Reverse()
        {
            head = Reverse_Recursive(head);
        }

        void Print(Node *h)
        {
            if (h != NULL)
            {
                cout << h->data << " ";
                Print(h->nextnode);
            }
        }

        void Print()
        {
            Print(head);
            cout << endl;
        }

        bool Has_Loop()
        {
            Node *slow = head;
            Node *fast = head;

            while (fast != NULL && fast->nextnode != NULL)
            {
                slow = slow->nextnode;
                fast = fast->nextnode->nextnode;

                if (slow == fast)
                {
                    return true;
                }
            }

            return false;
        }

        Node* GetHead() // Expose head pointer
        {
            return head;
        }
};

int main()
{
    LinkedList L1;

    // Adding nodes to the list
    L1.Add_End(1);
    L1.Add_End(2);
    L1.Add_End(3);
    L1.Add_End(4);

    // Print the original list
    cout << "Original List: ";
    L1.Print();

    // Check for loop (should be false)
    if (L1.Has_Loop())
    {
        cout << "Loop detected in the linked list!" << endl;
    }
    else
    {
        cout << "No loop detected in the linked list!" << endl;
    }

    // Create a loop for testing
    Node *temp = L1.GetHead()->nextnode->nextnode; // Point to the 3rd node
    Node *tail = L1.GetHead();
    while (tail->nextnode != NULL)
    {
        tail = tail->nextnode;
    }
    tail->nextnode = temp; // Create a loop

    // Check for loop again (should be true)
    if (L1.Has_Loop())
    {
        cout << "Loop detected in the linked list!" << endl;
    }
    else
    {
        cout << "No loop detected in the linked list!" << endl;
    }

    return 0;
}
