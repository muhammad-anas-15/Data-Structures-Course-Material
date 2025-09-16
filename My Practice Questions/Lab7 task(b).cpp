#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *nextNode;

    Node(int val) 
	{
        data = val;
        nextNode = NULL;
    }
};

class MinStack {
	
private:
    Node *top;        
    Node *min_ptr;     

public:
    MinStack() 
	{
        top = NULL;
        min_ptr = NULL; 
    }

    void push(int val) 
	{
        Node *newNode = new Node(val); 

        if (top == NULL) 
		{
            top = newNode; 
            min_ptr = new Node(val); 
        } 
		else 
		{
            newNode->nextNode = top; 
            top = newNode; 
            
            
            if (val <= min_ptr->data) 
			{
                Node *minNode = new Node(val); // Create a new node for min stack
                minNode->nextNode = min_ptr; 
                min_ptr = minNode; 
            }
        }
    }

    void pop() 
	{
        if (top == NULL) 
		{
            cout << "Stack is empty!" << endl;
            return;
        }

        
        if (top->data == min_ptr->data) //temperorary pointer to store minimum node
		{
            Node *temp1 = min_ptr; 
            min_ptr = min_ptr->nextNode; 
            delete temp1; 
        }

        // for popping element
        Node *temp2 = top; 
        top = top->nextNode; 
        delete temp2; 
    }

    int getMin() 
	{
        if (min_ptr == NULL) 
		{
            cout << "No minimum value. Stack is empty!" << endl;
            return -1; 
        }
        
        return min_ptr->data; 
    }

    void printStack() 
	{
        if (top == NULL) 
		{
            cout << "Stack is empty!" << endl;
            return;
        }

        Node *temp = top;
        cout << "Stack elements: ";
        
        while (temp != NULL) 
		{
            cout << temp->data << " ";
            temp = temp->nextNode;
        }
        cout << endl;
    }
};

int main() 
{
    MinStack S1;
    S1.push(9);
    S1.push(6);
    S1.push(3);
    S1.push(4);
    S1.push(2);

    S1.printStack(); 
    cout << "Minimum: " << S1.getMin() << endl; 

    S1.pop();
    S1.printStack(); 
    cout << "Minimum: " << S1.getMin() << endl; 

    S1.pop();
    S1.printStack(); 
    cout << "Minimum: " << S1.getMin() << endl;



    return 0;
}
