#include <iostream>
using namespace std;

class Queue {
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

        // Store the value at the rear index
        arr[rear] = value;

        // Move rear to the next position in a circular way
        rear = (rear + 1) % size;
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

        // Move front to the next position in a circular way
        front = (front + 1) % size;
        count--;
        return result;
    }

    int peek() 
	{
        if (isEmpty()) 
		{
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
            cout << arr[(front + i) % size] << " ";
        }
        cout << endl;
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
    q.enqueue(60);  // This will trigger a "Queue is full" message

    q.printQueue();

    q.dequeue();
    q.printQueue();

    cout << "Front element: " << q.peek() << endl;

    return 0;
}
