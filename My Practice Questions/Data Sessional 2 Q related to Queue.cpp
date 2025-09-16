#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int *front;  // Pointer to the front element in the queue
    int *rear;   // Pointer to the position where the next element will be inserted
    int size;    // Size of the queue array

public:
    // Constructor to initialize the queue
    Queue(int s) {
        size = s;
        arr = new int[size];
        front = rear = NULL;
    }

    // Destructor to free memory
    ~Queue() {
        delete[] arr;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == NULL;
    }

    // Check if the queue is full
    bool isFull() {
        return (rear + 1 == front || (front == arr && rear == arr + size - 1));
    }

    // Enqueue a value into the queue
    void Enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << val << "." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = arr;  // Initialize front and rear when the queue is empty
        } 
		else if (rear == arr + size - 1) 
		{
            rear = arr;  // Wrap around if rear reaches the end of the array
        } 
		else 
		{
            rear++;  // Move rear forward
        }

        *rear = val;  // Insert the value at the rear position
    }

    // Dequeue a value from the queue
    int Dequeue() 
	{
        if (isEmpty()) 
		{
            cout << "Queue Underflow! Cannot dequeue." << endl;
            return -1;
        }

        int result = *front;  // Retrieve the front element

        // Move front forward or wrap around if it reaches the end of the array
        if (front == rear) 
		{
            front = rear = NULL;  // Reset pointers when queue becomes empty
        } 
		else if (front == arr + size - 1) 
		{
            front = arr;  // Wrap around if front reaches the end of the array
        } 
		else 
		{
            front++;  // Move front forward
        }

        return result;
    }

    // Display the contents of the queue
    void Display() 
	{
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Queue: ";
        int *temp = front;
        do 
		{
            cout << *temp << " ";
            temp = (temp == arr + size - 1) ? arr : temp + 1;  // Wrap around if temp reaches end
        } while (temp != rear + 1);
        cout << endl;
    }
};

int main() {
    Queue q(5);

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50); // Queue is full after this
    q.Display();   // Output: Queue: 10 20 30 40 50

    cout << "Dequeued: " << q.Dequeue() << endl;  // Output: Dequeued: 10
    q.Enqueue(60);  // Enqueue after dequeuing
    q.Display();    // Output: Queue: 20 30 40 50 60

    cout << "Front element: " << q.Dequeue() << endl;  // Output: Front element: 20

    return 0;
}
