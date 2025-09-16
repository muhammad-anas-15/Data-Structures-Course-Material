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

class Stack
{
    private:
        Node *head, *top;
        int stack_size;
    
    public:
        Stack()
        {
            stack_size = 0;
            head = top = NULL;
        }
        
        // Check if the stack is empty
        bool isEmpty()
        {
            return top == NULL;
        }

        // Since a linked-list-based stack doesn't have a maximum size, we consider it "never full."
        bool isFull()
        {
            return false;
        }
        
        void Push(int val)
        {
            Node *newnode = new Node(val);
            
            if(head == NULL)
            {
                head = newnode;
                top = newnode;
            } 
            else
            {
                newnode->nextnode = top; // Point new node to current top
                top = newnode; // Move top to new node
            }
            stack_size++;
        }
        
        void Pop()
        {
            if(isEmpty()) // Use the isEmpty function to check
            {
                cout << "Stack is empty!" << endl;
                return;
            }
            
            Node *temp = top; // Store the current top node to delete it
            top = top->nextnode; // Move top to the next node (previous element)
            
            if(top == NULL) // If stack becomes empty, reset head
            {
                head = NULL;
            }
            
            delete temp; // Delete the old top
            stack_size--;
        }
        
        void Print()
        {
            if(isEmpty())
            {
                cout << "Stack is empty!" << endl;
                return;
            }
            
            Node *temp = top;
            while(temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->nextnode;
            }
            cout << endl;
        }
};

int main()
{
    Stack S1;
    S1.Push(5);
    S1.Push(6);
    S1.Push(7);
    S1.Push(8);
    
    S1.Print(); // Output: 8 7 6 5
    
    S1.Pop();
    S1.Print(); // Output: 7 6 5
    
    S1.Pop();
    S1.Print(); // Output: 6 5

    // Testing isEmpty and isFull
    cout << "Is stack empty? " << (S1.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (S1.isFull() ? "Yes" : "No") << endl;

    return 0;
}
