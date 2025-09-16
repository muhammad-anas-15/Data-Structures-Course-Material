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
    int stack_current_size;

public:
    Stack()
    {
        stack_current_size = 0;
        head = top = NULL;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    bool isFull() // A linked list stack cannot be full
    {
        return false;
    }

    void Push(int val)
    {
        Node *newnode = new Node(val);

        if (head == NULL)
        {
            head = newnode;
            top = newnode;
        }
        else
        {
            newnode->nextnode = top; // Point new node to current top
            top = newnode;           // Move top to new node
        }
        stack_current_size++;
    }

    void Pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }

        Node *temp = top;        // Store the current top node to delete it
        top = top->nextnode;     // Move top to the next node
        delete temp;             // Delete the old top
        stack_current_size--;

        if (top == NULL)         // If stack becomes empty, reset head
            head = NULL;
    }

    int Peak()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }

    bool isPrime(int n)
    {
        if (n < 2)
            return false;

        for (int i = 2; i <= n / 2; i++) // Loop up to n / 2 to check for divisors
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    void Print_Prime_Numbers(int num1, int num2)
    {
        // Push all prime numbers in the range onto the stack
        for (int i = num1; i <= num2; i++)
        {
            if (isPrime(i))
                Push(i);
        }

        // Print and pop primes from the stack
        while (!isEmpty())
        {
            cout << Peak() << " ";
            Pop();
        }
        cout << endl;
    }
};

int main()
{
    Stack S1;

    cout << "Is stack empty? " << (S1.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (S1.isFull() ? "Yes" : "No") << endl;

    // Print prime numbers in descending order
    S1.Print_Prime_Numbers(0, 100);

    return 0;
}
