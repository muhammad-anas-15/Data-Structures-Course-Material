#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *nextnode;
    Node *previous;  // Added previous pointer for doubly linked list
    
    Node(int val) : data(val), nextnode(NULL), previous(NULL) {}
};

class DoublyLinkedList {
private:
    Node *head;
    Node *tail; // Tail pointer for efficient access to the end of the list
    int List_Size;

public:
    DoublyLinkedList() : head(NULL), tail(NULL), List_Size(0) {}
    
    // Add node at the end of the doubly linked list
    void Add_End(int val) {
        Node *newnode = new Node(val);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            tail->nextnode = newnode;
            newnode->previous = tail;
            tail = newnode;
        }
        List_Size++;
    }
    
    // Print the list
    void Print() {
        Node *current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->nextnode;
        }
        cout << endl;
    }
    
    // Reverse the doubly linked list
    void Reverse(Node *&head_ref) {
        Node *previous = NULL;
        Node *current = head_ref;
        Node *forward = NULL;
        
        while (current != NULL) {
            forward = current->nextnode;
            current->nextnode = previous;
            current->previous = forward;  // Adjust the previous pointer
            previous = current;
            current = forward;
        }
        head_ref = previous;  // Update the head to the new reversed head
    }
    
    // Find the middle node of the doubly linked list
    Node* middle() {
        if (head == NULL) return NULL;
        
        Node *temp1 = head;
        Node *temp2 = head;
        
        // Use two pointers to find the middle
        while (temp2 != NULL && temp2->nextnode != NULL) {
            temp2 = temp2->nextnode->nextnode;
            temp1 = temp1->nextnode;
        }
        return temp1;
    }
    
    // Check if the doubly linked list is a palindrome
    bool Check_Palindrome() {
        if (head == NULL || head->nextnode == NULL) {
            return true;  // Empty or single node list is always a palindrome
        }
        
        // Find the middle of the list
        Node *middle_node = middle();
        if (middle_node == NULL) return false;
        
        // Split the list into two halves
        Node *head1 = head;
        Node *head2 = middle_node->nextnode;
        middle_node->nextnode = NULL; // Split the list at the middle
        
        // Reverse the second half of the list
        Reverse(head2);
        
        // Compare the two halves
        Node *temp1 = head1;
        Node *temp2 = head2;
        
        while (temp2 != NULL) 
		{
            if (temp1->data != temp2->data) {
                // Restore the second half to its original order before returning
                Reverse(head2);
                
                middle_node->nextnode = head2;  // Reconnect the two halves
                head2->previous = middle_node;
                return false;
            }
            temp1 = temp1->nextnode;
            temp2 = temp2->nextnode;
        }
        
        // Restore the second half to its original order
        Reverse(head2);
        middle_node->nextnode = head2;  // Reconnect the two halves
        head2->previous = middle_node;
        
        return true;
    }
};

int main() {
    DoublyLinkedList L1;
    L1.Add_End(1);
    L1.Add_End(2);
    L1.Add_End(3);
    L1.Add_End(2);
    L1.Add_End(4);

    L1.Print();
    cout << "Is palindrome: " << (L1.Check_Palindrome() ? "Yes" : "No") << endl;
    L1.Print();

    return 0;
}
