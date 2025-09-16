#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node *next;

    Node(int val) 
    {
        data = val;
        next = NULL;
    }
};

class LinkedList 
{
private:
    Node *front;
    Node *rear;  

public:
    LinkedList() 
    {
        front = rear = NULL;
    } 

    void push(int value) 
    {
        Node* newNode = new Node(value);
        
        if (front == NULL) 
        {
            front = rear = newNode;
        } 
        else 
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int pop() 
    {
        if (front == NULL) return -1;  // return -1 if list is empty

        int val = front->data;
        Node* temp = front;
        front = front->next;
        
        if (front == NULL) 
        {
            rear = NULL;
        }

        delete temp;
        return val;
    }

    void rotate_necklace(int steps) // steps denote k value
    {
        if (front == NULL || front->next == NULL || steps == 0) return;

        int listSize = 0;
        
        Node* current = front;
        
        while (current != NULL) 
        {
            listSize++;
            current = current->next;
        }

        steps = steps % listSize; // normalize steps if step are greater than list size
        
        if (steps == 0) return; 

        for (int count = 0; count < steps; count++) 
        {
            int val = pop(); // Remove the first node
            push(val);       // Add it to the end of the list
        }
    }

    void printList() 
    {
        Node* temp = front;
        
        while (temp) 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

//    void clear() // Clear the list after each test case
//    {
//        while (front) 
//        {
//            Node* temp = front;
//            front = front->next;
//            delete temp;
//        }
//        rear = NULL;
//    }
};

int main() 
{
    int t;  // no of test cases
    cin >> t;

    while (t--) 
    {
        int pearls, position;
        cin >> pearls >> position;  

        LinkedList necklace;

        
        for (int i = 0; i < pearls; i++) 
        {
            int per;
            cin >> per;
            
            necklace.push(per);  
        }

        
        necklace.rotate_necklace(position); 

        
        necklace.printList(); 

       
        //necklace.clear();  // Clear the linked list for the next test case
    }

    return 0;
}
