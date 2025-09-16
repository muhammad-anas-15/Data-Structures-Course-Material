#include <iostream>
using namespace std;

class Node // node class implementation
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

class Stack //stack class implementation
{
private:
    Node *head, *top; //heap pointer is at head and top pointer store address of top value
    
    int stack_current_size; //variable will store stack_current_size

public:
    Stack() //constructor
    {
        stack_current_size = 0; //inititally
        head = top = NULL;
    }

    bool isEmpty() //fun to check stack is empty
    {
        return top == NULL;
    }


    void Push(int val) // function for inserting value in stack
    {
        Node *newnode = new Node(val); // first made new node

        if (head == NULL) // if there is no not present earlier made it.
        {
            head = newnode;
            top = newnode;
        }
        else // otherwise add at top of stack
        {
            newnode->nextnode = top; // Point new node to current top
            top = newnode;           // Move top to new node
        }
        stack_current_size++; // increment stacksize after inserting an element.
    }

    void Pop() // function for removing values from stack
    {
        if (isEmpty()) // first check
        {
            cout << "Stack is empty!" << endl;
            return;
        }

        Node *temp = top;        // first store stack top value beforing deleting.
        top = top->nextnode;     // move top to next node.
        
        delete temp;             //delete top value.
        
        stack_current_size--;   // also decrease stacksize.

        if (top == NULL)         // If stack is empty, head is null now
        {
        	 head = NULL;
		}
           
    }

    int Peak() // function for getting top value of stack
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        
        return top->data;
    }

    bool isPrime(int n) // function to check a specific number is prime or not
    {
        if (n < 2)   // if the number is divisible by 2 it means it is even not prime
        {
        	 return false;
		}
           

        for (int i = 2; i <= n / 2; i++) // iterate loo untile number half to check either it is divivsible
        {
            if (n % i == 0) // if number is divisible then it is not prime
            {
            	return false;
			}
                
        }
        //otherwise if above conditions fails then it is prime
        return true;
    }

    void Print_Prime_Numbers(int num1, int num2) // function for print prime numbers upto 100
    {
        
        for (int i = num1; i <= num2; i++)// first push all prime numbers in the range onto the stack .
        {
            if (isPrime(i))
            {
            	Push(i);
			}
                
        }

        
        while (!isEmpty())// now start printing then and pop primes from the stack.
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

    cout<<"Prime Numbers upto 100 are:\n\n";
    // Print prime numbers in descending order
    S1.Print_Prime_Numbers(0, 100);

    return 0;
}
