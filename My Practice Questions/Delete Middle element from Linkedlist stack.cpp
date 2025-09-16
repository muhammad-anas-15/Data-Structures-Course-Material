#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* nextnode;

    Node(int val)
    {
        data = val;
        nextnode = NULL;
    }
};

class Stack
{
private:
    Node* top;
    int stack_size;

public:
    Stack()
    {
        stack_size = 0;
        top = NULL;
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return top == NULL;
    }

    // Push an element onto the stack
    void Push(int val)
    {
        Node* newnode = new Node(val);
        newnode->nextnode = top; // Point new node to current top
        top = newnode;           // Move top to new node
        stack_size++;
    }

    // Pop the top element from the stack
    int Pop()
    {
        if (isEmpty()) // Check if the stack is empty
        {
            cout << "Stack is empty!" << endl;
            return -1; // Return a sentinel value
        }

        Node* temp = top; // Store the current top node to delete it
        top = top->nextnode; // Move top to the next node
        
        int poppedValue = temp->data; // Store the data to return
        
        delete temp; // Delete the old top
        stack_size--;
        return poppedValue; // Return the popped value
    }

    // Print the stack elements
    void Print()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }

        Node* temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->nextnode;
        }
        cout << endl;
    }

    int DeleteMiddle()
    {
        if (isEmpty())
        {
            cout << "Stack is empty! Cannot delete middle element." << endl;
            return 0;
        }

        Stack tempStack; 
        
        int midIndex = stack_size / 2; // Calculate the middle index

        // Move elements to the temporary stack until reaching the middle
        for (int i = 0; i < midIndex; i++)
        {
            tempStack.Push(Pop());
        }

        // Pop the middle element (current top of the main stack)
        int val = Pop();

        // Restore the elements from the temporary stack back to the main stack
        while (!tempStack.isEmpty())
        {
            Push(tempStack.Pop());
        }
        return val;
    }
};

int main()
{
    Stack S1;
    S1.Push(1);
    S1.Push(2);
    S1.Push(3);
    S1.Push(4);
    S1.Push(5);

    cout << "Original stack: ";
    S1.Print(); 

    cout<<S1.DeleteMiddle()<<endl;
    cout << "Stack after deleting middle element: ";
    S1.Print(); 

    return 0;
}
