#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;        // Dynamically allocated array
    int* front;      // Pointer to the front element
    int* rear;       // Pointer to the next insertion point

    int size;        // Maximum size of the queue
    int count;       // Current number of elements

public:
    Queue(int size) 
    {
        this->size = size;
        arr = new int[size];
        
        front = rear = NULL;  // Both front and rear start as null
        count = 0;
    }

    ~Queue() 
    {
        delete[] arr;
    }

    bool isEmpty() 
    {
        return front == NULL; // Queue is empty if front is null
    }

    bool isFull() 
    {
        return (rear == arr + size && front == arr) || (rear + 1 == front); // Queue is full if rear wraps around to front
    }

    void enqueue(int value) 
    {
        if (isFull()) 
        {
            cout << "Queue is full. Cannot enqueue " << value << "." << endl;
            return;
        }

        if (isEmpty()) 
        {
            front = rear = arr; // Initialize front and rear if queue was empty
        } 
        else 
        {
            rear = arr + ((rear - arr + 1) % size); // Move rear to the next position in a circular way
        }

        *rear = value; // Store the value at the rear pointer
        count++;
    }

    int dequeue() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }

        int result = *front; // Retrieve the value at the front pointer

        if (front == rear) 
        {
            // Reset the queue if it becomes empty
            front = rear = nullptr;
        } 
        else 
        {
            front = arr + ((front - arr + 1) % size); // Move front to the next position in a circular way
        }

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
        return *front; // Return the value at the front pointer
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
            cout << *(arr + ((front - arr + i) % size)) << " ";
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
