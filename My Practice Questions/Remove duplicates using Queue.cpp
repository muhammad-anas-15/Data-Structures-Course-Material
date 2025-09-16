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
        arr[rear] = value;
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
        front = (front + 1) % size;
        count--;
        return result;
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
		/{
            cout << arr[(front + i) % size] << " ";
        }
        cout << endl;
    }

    void removeDuplicates() 
	{
        int originalSize = count;

        for (int i = 0; i < originalSize; i++) 
		{
            int current = dequeue(); // Dequeue each element one by one
            
            bool isDuplicate = false;

            // Check remaining elements for duplicates
            for (int j = 0; j < count; j++) 
			{
                int temp = dequeue();
                
                if (temp == current) 
				{
                    isDuplicate = true; // Mark as duplicate
                }
                
                enqueue(temp); // Re-enqueue to restore original order
            }

            // If not a duplicate, enqueue it back; otherwise, skip
            if (!isDuplicate)
			{
                enqueue(current);
            }
        }
    }
};

int main() {
    Queue q(10);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(20); // Duplicate
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(30); // Duplicate

    cout << "Original ";
    q.printQueue();

    // Remove duplicates
    q.removeDuplicates();

    cout << "After removing duplicates ";
    q.printQueue();

    return 0;
}
