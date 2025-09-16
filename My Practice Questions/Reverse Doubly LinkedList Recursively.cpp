#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next, *previous;

    Node(int d) {
        this->data = d;
        next = previous = NULL;
    }
};

class Doubly_LinkedList {
private:
    Node *head;
    int List_size;

public:
    Doubly_LinkedList() {
        head = NULL;
        List_size = 0;
    }

    void Print() {
        Node *current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void Add_Start(int val) {
        Node *newnode = new Node(val);
        if (head == NULL) {
            head = newnode;
        } else {
            newnode->next = head;
            head->previous = newnode;
            head = newnode;
        }
        List_size++;
    }

    void Add_Last(int val) {
        Node *newnode = new Node(val);
        if (head == NULL) {
            head = newnode;
        } else {
            Node *current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newnode;
            newnode->previous = current;
        }
        List_size++;
    }

    void Add_pos(int pos, int val) {
        if (pos < 1 || pos > List_size + 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node *newnode = new Node(val);
        if (pos == 1) {
            Add_Start(val);
        } else {
            Node *current = head;
            int count = 1;
            while (count < pos - 1 && current != NULL) {
                current = current->next;
                count++;
            }

            if (current->next == NULL) {
                Add_Last(val);
            } else {
                newnode->next = current->next;
                newnode->previous = current;
                current->next->previous = newnode;
                current->next = newnode;
            }
        }
        List_size++;
    }

    Node* Reverse_Recursive(Node *current) 
	{
        if (current == NULL) {
            return NULL;
        }

        if (current->next == NULL) 
		{
            head = current; // Update head to the last node
            
            return current; // Return the last node
        }

        Node *newHead = Reverse_Recursive(current->next);


        current->next->next = current; 
        current->previous = current->next;
        
        current->next = NULL; 

        return newHead; 
    }

    void Reverse() 
	{
        Reverse_Recursive(head);
    }
};

int main() {
    Doubly_LinkedList D1;
    D1.Add_Start(4);
    D1.Add_Start(5);
    D1.Add_Start(6);
    
    D1.Print();            // Before reversal: 6 5 4
    D1.Reverse();
    D1.Print();            // After reversal: 4 5 6

    return 0;
}
