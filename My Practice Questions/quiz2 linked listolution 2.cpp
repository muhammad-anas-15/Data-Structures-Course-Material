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
void Algorithm() 
{
    Node* current = head;
    Node* group = NULL, *newHead = NULL, *tail = NULL;
    int count = 0;
    int groupIndex = 1; // To keep track of odd/even group

    while (current != NULL) {
        group = current;

        // Traverse through the current group of 3 nodes
        for (count = 1; count < 3 && current != NULL; ++count) {
            current = current->nextnode;
        }

        // Detach the group from the rest of the list
        if (current != NULL) {
            Node* nextGroup = current->nextnode;
            current->nextnode = NULL; // End current group
            current = nextGroup; // Move to the next group
        }

        // Reverse odd-numbered groups, leave even-numbered groups as is
        if (groupIndex % 2 == 1) { // Odd group
            group = Reverse(group); 
        }

        // Connect the groups
        if (newHead == NULL) {
            newHead = group; // First group becomes new head
        } 
		else {
            tail->nextnode = group; // Join this group to the previous part
        }

        // Move tail to the last node of the current group
        tail = group;
        while (tail != NULL && tail->nextnode != NULL) {
            tail = tail->nextnode;
        }

        groupIndex++; // Move to the next group (increment the group number)
    }

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
    L1.Algorithm();
    
    cout << "\n\nModified List after reversing Part 1 and Part 3:" << endl;
    L1.Print();

    return 0;
}
