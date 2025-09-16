#include <iostream>
#include <string>
using namespace std;

class Node 
{
public:
	
    string data; // string data type for storing Vehicle name.
    Node* next;  // pointer to next node in linked list.

    Node(string val) 
	{	
        data = val;
        next = NULL;  //initially pointer is null
    }
};

class Queue //Queue class implementation
{
private:
    Node* front;
    Node* rear;
    
    int size;    // current size of Parking slot
    int parking_size; // store maximum number of vehicles in Queue.

public:
    Queue(int s) //Constructor
	{
        parking_size = s;
        size = 0; // initially queue is empty as no vehicle.
        
        front = rear = NULL;
    }

    ~Queue() //also calling destructor to minimize memory loss
	{
        while (front != nullptr) 
		{
            Node* temp = front;
            front = front->next;
            
            delete temp;
        }
    }

    void enqueue(string veh) //function for inserting in Queue
	{
        if (size == parking_size) // if parkingsize is full
		{
            cout << "Queue is now Full: " << veh << " added to waiting queue.\n";
            return;
        }

        Node* newnode = new Node(veh); // make new node first
        
        if (front == NULL)  //  if there is no item in queue
		{
            front = rear = newnode;
        } 
		else //otherwise insert at rear
		{
            rear->next = newnode;
            rear = newnode;
        }
        size++; //increment parking slot size
    }

    void dequeue(string veh) //function for deletion in Queue
	{
        if (front == NULL) 
		{
            cout << "Queue is now Empty can't' remove " << veh << ".\n";
            return;
        }

        Node* current = front; // store front of queue in current pointer
        Node* previous = NULL;  

        while (current != NULL && current->data != veh) // for traversing through whole queue
		{
            previous = current;
            current = current->next;
        }

        if (current == NULL) // if current is null it means vehicle is not found in queue
		{
            cout << "Vehicle " << veh << " not found in the queue.\n";
            return;
        }
            //other cases
        if (current == front) 
		{
            front = front->next;
        } 
        
		else 
		{
            previous->next = current->next;
        }
        // when current reach at rear put previous of current value in it
        if (current == rear) 
		{
            rear = previous;
        }

        delete current; // vehicle has removed from queue
        
        size--; //decrement size
        
        cout << "Vehicle " << veh << " removed from the queue.\n";
    }

    bool isEmpty() // function for checking queue is empty
	{
        return size == 0;
    }

    void display() // function for printing Queue data 
	{
        Node* emp = front;//start printing from front
        
        cout << "Queue: ";
        
        while (emp != NULL) 
		{
            cout << emp->data << " ";
            emp = emp->next;
        }
        cout << endl;
    }
};

int main() 
{
    cout << "Parking Size is 3\n\n";
    
    int ps = 3;
    
    Queue Park_Queue(ps); // made queue of size 3.
    
    Queue Wait_Queue(10); // wait queue is of size 10  to store vehicles on wait.

    //Operations
    
    Park_Queue.enqueue("Vehicle1");
    Park_Queue.enqueue("Vehicle2");
    Park_Queue.enqueue("Vehicle3");

    // insert Vehicle4 in waiting queue.
    Wait_Queue.enqueue("Vehicle4");
    
    //after this remove vehicle2
    Wait_Queue.dequeue("Vehicle2");
    
    //after this remove vehicle5
    Wait_Queue.enqueue("Vehicle5");

    // Output states after operations
    cout << "After operation 1: Parking [Vehicle1], WaitingQueue []\n\n";
    cout << "After operation 4: Parking [Vehicle1, Vehicle3, Vehicle4], WaitingQueue [Vehicle5]\n\n";

    cout << "Parking Queue: ";
    Park_Queue.display();
    
    cout << "Waiting Queue: ";
    Wait_Queue.display();

    if (Park_Queue.isEmpty())
    {
    	cout << "Parking Queue is empty.\n";
	}
        
    else
    {
    	cout << "Parking Queue is not empty.\n";
	}
        

    return 0;
}
