#include<iostream>
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
           top = NULL;
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
            if(!isFull())
            {
                top++;
                *top = val;
            }
            else
            {
                cout << "Stack Overflow!" << endl;
            }
        }

        void Pop()
        {
            if(!isEmpty())
            {
                top--;
            }
            else
            {
                cout << "Stack Underflow!" << endl;
            }
        }

        int Peak()
        {
            if(!isEmpty())
            {
                return *top;
            }
            cout << "Stack is Underflow! " << endl;
            return -1; // Return a sentinel value
        }

        void Print()
        {
            if(!isEmpty())
            {
                int *temp = top;
                while(temp >= arrhead) // Print from top to bottom
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
};

int main()
{
    Stack S1(5);
    S1.Push(1);
    S1.Push(2);
    S1.Push(3);
    S1.Push(4);
    S1.Push(5);

    S1.Pop();
    S1.Print();

    return 0;
}
