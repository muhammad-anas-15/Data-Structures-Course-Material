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
		{
            cout << arr[(front + i) % size] << " ";
        }
        cout << endl;
    }

    void sortQueue() 
	{
        for (int i = 0; i < count; i++) 
		{
            int min_Index = -1;
            int min_Value = 65345;

            
            for (int j = 0; j < count; j++) // Find the smallest element in the queue
			{
                int current = dequeue();

                
                if (current < min_Value && j >= i) // Update minimum value and index 
				{
                    min_Value = current;
                    min_Index = j;
                }

                enqueue(current); // Reinsert current element back
            }

            
            for (int k = 0; k < count; k++) // Move the smallest element to the front
			{
                int current = dequeue();

                if (k != min_Index) 
				{
                    enqueue(current); // Reinsert non-min elements back
                }
            }

            
            enqueue(min_Value);// Finally enqueue the minimum element at its sorted position
        }
    }
};

int main() {
    Queue q(10);

    q.enqueue(30);
    q.enqueue(10);
    q.enqueue(50);
    q.enqueue(20);
    q.enqueue(40);

    cout << "Original ";
    q.printQueue();

    // Sort the queue
    q.sortQueue();

    cout << "Sorted ";
    q.printQueue();

    return 0;
}
