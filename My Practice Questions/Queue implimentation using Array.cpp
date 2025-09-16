#include <iostream>
using namespace std;

class Queue 
{
private:
    int *arr;   // Array to store queue elements
    int front;  // Index of the front element
    int rear;   // Index of the next position for adding an element
    int size;   // Maximum size of the queue

public:
    Queue(int size) 
	{
        this->size = size;
        arr = new int[size];
        front = 0;     // Initialize front index to 0
        rear = 0;      // Initialize rear index to 0
    }

    ~Queue() 
	{
        delete[] arr; // Free allocated memory
    }

    // Check if the queue is empty
    bool isEmpty() 
	{
        return front == rear; // Queue is empty if front equals rear
    }

    // Check if the queue is full
    bool isFull() 
	{
        return rear == size; // Queue is full if rear equals size
    }

    // Enqueue an element
    void enqueue(int value) 
	{
        if (isFull()) 
		{
            cout << "Queue is full. Cannot enqueue " << value << "." << endl;
            return;
        }
        arr[rear] = value; // Add the element at the rear index
        rear++;            // Move the rear index forward
    }

    // Dequeue an element
    int dequeue() 
	{
        if (isEmpty()) 
		{
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
        int result = arr[front]; // Get the front element
        front++; // Move the front index forward
        return result;
    }

    // Peek at the front element
    int peek() 
	{
        if (isEmpty()) 
		{
            cout << "Queue is empty. Cannot peek." << endl;
            return -1;
        }
        return arr[front]; // Return the front element
    }

    // Print the queue elements
    void printQueue() 
	{
        if (isEmpty()) 
		{
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue: ";
        for (int i = front; i < rear; i++) { // Print from front to rear
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // This will trigger a "Queue is full" message

    q.printQueue();

    q.dequeue();
    q.printQueue();

    cout << "Front element: " << q.peek() << endl;

    return 0;
}
