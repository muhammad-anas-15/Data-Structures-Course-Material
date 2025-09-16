#include <iostream>
using namespace std;

class Queue {
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue(int size);
    ~Queue();
    void enqueue(int x);
    int dequeue();
    void display() const;
};

Queue::Queue(int size) {
    this->size = size;
    front = rear = -1;
    Q = new int[size];
}

Queue::~Queue() {
    delete[] Q;
}

void Queue::enqueue(int x) {
    if (rear == size - 1)
        cout << "Queue is Full" << endl;
    else {
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue() {
    int x = -1;
    if (front == rear)
        cout << "Queue is Empty" << endl;
    else {
        front++;
        x = Q[front];
    }
    return x;
}

void Queue::display() const {
    for (int i = front + 1; i <= rear; i++)
        cout << Q[i] << " ";
    cout << endl;
}

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << q.dequeue() << endl;
    return 0;
}
