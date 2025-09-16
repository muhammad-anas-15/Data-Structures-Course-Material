#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;
    int capacity; // Maximum number of items allowed in the queue

public:
    Queue(int cap) {
        capacity = cap;
        size = 0;
        front = rear = nullptr;
    }

    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void enqueue(string x) {
        if (size == capacity) {
            cout << "Queue is Full: " << x << " added to waiting queue.\n";
            return;
        }

        Node* newnode = new Node(x);
        if (front == nullptr) {
            front = rear = newnode;
        } else {
            rear->next = newnode;
            rear = newnode;
        }
        size++;
    }

    void dequeue(string vehicle) {
        if (front == nullptr) {
            cout << "Queue is Empty. Cannot remove " << vehicle << ".\n";
            return;
        }

        Node* current = front;
        Node* prev = nullptr;

        while (current != nullptr && current->data != vehicle) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Vehicle " << vehicle << " not found in the queue.\n";
            return;
        }

        if (current == front) {
            front = front->next;
        } else {
            prev->next = current->next;
        }

        if (current == rear) {
            rear = prev;
        }

        delete current;
        size--;
        cout << "Vehicle " << vehicle << " removed from the queue.\n";
    }

    bool isEmpty() const {
        return size == 0;
    }

    void display() const {
        Node* temp = front;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    cout << "Parking Size: 3\n";
    int parkingSize = 3;
    Queue parkingQueue(parkingSize);
    Queue waitingQueue(100); // Large enough to handle the waiting list

    parkingQueue.enqueue("Vehicle1");
    parkingQueue.enqueue("Vehicle2");
    parkingQueue.enqueue("Vehicle3");

    // Overflow to waiting queue
    waitingQueue.enqueue("Vehicle4");
    parkingQueue.dequeue("Vehicle2");
    parkingQueue.enqueue("Vehicle5");

    // Output states after operations
    cout << "After operation 1: Parking [Vehicle1], WaitingQueue []\n";
    cout << "After operation 4: Parking [Vehicle1, Vehicle3, Vehicle4], WaitingQueue [Vehicle5]\n";

    cout << "Parking Queue: ";
    parkingQueue.display();
    cout << "Waiting Queue: ";
    waitingQueue.display();

    if (parkingQueue.isEmpty())
        cout << "Parking Queue is empty.\n";
    else
        cout << "Parking Queue is not empty.\n";

    return 0;
}
