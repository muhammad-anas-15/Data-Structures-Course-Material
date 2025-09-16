#include <iostream>
#include <cstdlib>

class Queue {
private:
    int size;
    int front;
    int rear;
    int* Q;

public:
    // Constructor to create the queue with a given size
    Queue(int size) {
        this->size = size;
        front = rear = 0;
        Q = new int[this->size];
    }

    // Destructor to free allocated memory
    ~Queue() {
        delete[] Q;
    }

    // Function to add an element to the queue
    void enqueue(int x) {
        if ((rear + 1) % size == front) {
            std::cout << "Queue is Full" << std::endl;
        } else {
            rear = (rear + 1) % size;
            Q[rear] = x;
        }
    }

    // Function to remove an element from the queue
    int dequeue() {
        int x = -1;
        if (front == rear) {
            std::cout << "Queue is Empty" << std::endl;
        } else {
            front = (front + 1) % size;
            x = Q[front];
        }
        return x;
    }

    // Function to display the elements in the queue
    void display() const {
        int i = front + 1;
        do {
            std::cout << Q[i] << " ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
        std::cout << std::endl;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);  // This will indicate that the queue is full

    q.display();

    std::cout << q.dequeue() << " ";
    q.display();

    return 0;
}
