#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *nextnode;
        
        Node(int val) {
            data = val;
            nextnode = NULL;
        }
};

class LinkedList {
    private:
        Node *head, *current;
        int List_Size;
    
    public:
        LinkedList() {
            head = current = NULL;
            List_Size = 0;
        }	
        
        // Add a node at the end of the list
        void Add_End(int val) {
            Node *newnode = new Node(val);
            if(head == NULL || List_Size == 0) {
                head = current = newnode;
                List_Size++;
            } else {
                current->nextnode = newnode;
                current = newnode;
                List_Size++;
            }
        }
        
        // Print the entire list
        void Print() {
            current = head;
            while(current != NULL) {
                cout << current->data << " ";
                current = current->nextnode;
            }
        }
        
        // Reverse a given linked list
        Node* Reverse(Node* head) {
            Node *previous = NULL, *forward = NULL, *current = head;
            while(current != NULL) {
                forward = current->nextnode;
                current->nextnode = previous;
                previous = current;
                current = forward;
            }	
            return previous;  // New head after reversing
        }
        
        // Function to break the list into parts of 3, reverse odd-numbered parts, and join back
        void Algorithim() {
            Node* current = head;
            Node* part1 = NULL, *part2 = NULL, *part3 = NULL, *newHead = NULL, *tail = NULL;
            int count = 0;
            
            // Process first 3 nodes as part 1
            part1 = current;
            for (count = 1; count < 3 && current != NULL; ++count) {
                current = current->nextnode;
            }
            if (current != NULL) {
                Node* nextPart = current->nextnode;
                current->nextnode = NULL;
                current = nextPart;
            }
            
            // Process next 3 nodes as part 2
            part2 = current;
            for (count = 1; count < 3 && current != NULL; ++count) {
                current = current->nextnode;
            }
            if (current != NULL) {
                Node* nextPart = current->nextnode;
                current->nextnode = NULL;
                current = nextPart;
            }
            
            // Process next 3 nodes as part 3
            part3 = current;
            for (count = 1; count < 3 && current != NULL; ++count) {
                current = current->nextnode;
            }
            if (current != NULL) {
                Node* nextPart = current->nextnode;
                current->nextnode = NULL;
                current = nextPart;
            }
            
            // Reverse odd parts (Part 1 and Part 3)
            part1 = Reverse(part1);
            part3 = Reverse(part3);
            
            // Join parts: part1 -> part2 -> part3
            newHead = part1;
            tail = part1;
            while(tail != NULL && tail->nextnode != NULL) {
                tail = tail->nextnode;
            }
            tail->nextnode = part2;  // Join part2 after part1
            while(tail != NULL && tail->nextnode != NULL) {
                tail = tail->nextnode;
            }
            tail->nextnode = part3;  // Join part3 after part2
            
            // Update the head of the list to point to newHead
            head = newHead;
        }
};

int main() {
    LinkedList L1;
    
    // Adding elements to the linked list
    for(int i = 1; i <= 20; i++) {
        L1.Add_End(i);
    }

    // Print the original list
    cout << "Original List:" << endl;
    L1.Print();

    // Perform the algorithm: splitting, reversing, and joining
    L1.Algorithim();
    
    cout << "\n\nModified List after reversing Part 1 and Part 3:" << endl;
    L1.Print();

    return 0;
}
