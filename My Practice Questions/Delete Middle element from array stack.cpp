#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    int *arrhead, *top;
    int size;

public:
    Stack(int size)
    {
        this->size = size;
        arrhead = new int[size];
        top = arrhead - 1; // Start before the first element
    }

    ~Stack()
    {
        delete[] arrhead;
        top = nullptr;
    }

    bool isFull()
    {
        return top >= arrhead + size - 1;
    }

    bool isEmpty()
    {
        return top < arrhead;
    }

    void Push(int val)
    {
        if (!isFull())
        {
            top++;
            *top = val;
        }
        else
        {
            cout << "Stack Overflow!" << endl;
        }
    }

    int Pop()
    {
        if (!isEmpty())
        {
            int poppedValue = *top;
            top--;
            return poppedValue;
        }
        else
        {
            cout << "Stack Underflow!" << endl;
            return -1; // Return a sentinel value
        }
    }

    int Peak()
    {
        if (!isEmpty())
        {
            return *top;
        }
        cout << "Stack is Underflow! " << endl;
        return -1; // Return a sentinel value
    }

    void Print()
    {
        if (!isEmpty())
        {
            int *temp = top;
            while (temp >= arrhead) // Print from top to bottom
            {
                cout << *temp << " ";
                temp--;
            }
            cout << endl;
        }
        else
        {
            cout << "Stack is Empty!" << endl;
        }
    }

    void DeleteMiddle(int middleIndex, int currentIndex = 0)
    {
        if (isEmpty() || currentIndex > middleIndex)
            return;

        int x = Pop();

        DeleteMiddle(middleIndex, currentIndex + 1);

        // Push the element back only if it's not the middle element
        if (currentIndex != middleIndex)
        {
            Push(x);
        }
    }
};

int main()
{
    Stack S1(5);
    S1.Push(1);
    S1.Push(2);
    S1.Push(3);
    S1.Push(4);
    S1.Push(5);

    cout << "Stack before deleting the middle element: ";
    S1.Print();

    // Calculate the middle index (zero-based indexing)
    int middleIndex = 2; // For a stack with 5 elements, the middle is at index 2
    S1.DeleteMiddle(middleIndex);

    cout << "Stack after deleting the middle element: ";
    S1.Print();

    return 0;
}
