#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;

    Node(int val) 
    {
        data = val;
        next = NULL;
    }
};

class Queue 
{
private:
    Node* front;
    Node* rear;

public:
    Queue() 
    {
        front = rear = NULL;
    }

    ~Queue() 
    {
        while (front != NULL) 
        {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void enqueue(int x) 
    {
        Node* newnode = new Node(x);  
        
        if (newnode == NULL) 
        {
            cout << "Queue is Full" << endl;
            return;
        }

        if (front == NULL) 
        {
            front = rear = newnode;
        } 
        else 
        {
            rear->next = newnode;  
            rear = newnode;      
        }
    }

    int dequeue() 
    {
        int x = -1;  

        if (front == NULL) 
        {
            cout << "Queue is Empty" << endl;
        } 
        else 
        {
            Node* temp = front;    
            x = temp->data;        
            front = front->next;   
            
            delete temp;          
        }
        return x;
    }

    bool isEmpty() const 
    {
        return front == NULL;
    }

    void display() const 
    {
        Node* temp = front;  
        while (temp != NULL) 
        {
            cout << temp->data << " "; 
            temp = temp->next;          
        }
        cout << endl;
    }
};

int main() 
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();  

    cout << q.dequeue() << " ";  
    q.display();  

    if (q.isEmpty())
        cout << "Queue is empty." << endl;
    else
        cout << "Queue is not empty." << endl;

    return 0;
}
