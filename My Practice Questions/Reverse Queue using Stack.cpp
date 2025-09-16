#include <iostream>
#include <stack> 
using namespace std;

class Queue 
{
private:
    int *arr;   
    int front; 
    int rear;   
    int size;   
    int count;

public:
    Queue(int size) 
	{
        this->size = size;
        arr = new int[size];
        front = rear = 0;       
        count = 0;   
    }

    ~Queue() 
	{
        delete[] arr;
    }

    bool isEmpty() 
	{
        return count == 0; 
    }

    bool isFull() 
	{
        return count == size; 
    }

    void enqueue(int value)
	{
        if (isFull()) 
		{
            cout << "Queue is full. Cannot enqueue " << value << "." << endl;
            return;
        }
        
        arr[rear] = value; 
        rear = (rear + 1) % size; // Move rear in a circular manner
        count++; 
    }

    int dequeue() 
	{
        if (isEmpty()) 
		{
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
        
        int result = arr[front]; 
        front = (front + 1) % size; // Move the front in a circular manner
        count--; 
        return result;
    }

    int peek() 
	{
        if (isEmpty()) {
            cout << "Queue is empty. Cannot peek." << endl;
            return -1;
        }
        return arr[front]; 
    }

    void printQueue() 
	{
        if (isEmpty()) 
		{
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < count; i++) 
		{ 
            cout << arr[(front + i) % size] << " "; // Access in circular manner
        }
        cout << endl;
    }

    void ReverseQueue() 
	{
        stack<int> S1; 
        
        
        while (!isEmpty()) // Dequeue all elements from the queue and push them onto the stack
		{
            int element = dequeue();
            S1.push(element);
        }

       
        while (!S1.empty())  // Pop elements from the stack and enqueue them back to the queue
		{
            int element = S1.top();
            S1.pop();
            enqueue(element);
        }
    }
};

int main() 
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    

    q.printQueue();


    cout << "Front element: " << q.peek() << endl;

    // Reverse the queue
    q.ReverseQueue();
    cout << "Reversed ";
    q.printQueue(); // Print the reversed queue

    return 0;
}
