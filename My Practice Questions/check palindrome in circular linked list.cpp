#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* nextnode;

    Node(int d) {
        data = d;
        nextnode = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void Add_CLL(int pos, int val) {
        if (pos < 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* newnode = new Node(val);

        // Case 1: If the list is empty
        if (head == nullptr) {
            head = newnode;
            newnode->nextnode = head; // Circular reference to itself
        } else if (pos == 1) { // Case 2: Insertion at the beginning
            newnode->nextnode = head;
            Node* current = head;
            while (current->nextnode != head) { // Traverse to the last node
                current = current->nextnode;
            }
            current->nextnode = newnode; // Last node points to the new head
            head = newnode; // Update head
        } else { // Case 3: Insertion at a position other than the first
            Node* current = head;
            for (int i = 1; i < pos - 1; i++) { // Traverse to the (pos-1) node
                current = current->nextnode;
            }
            newnode->nextnode = current->nextnode; // Set new node's next to the current node's next
            current->nextnode = newnode; // Link current node to the new node
        }
    }

    void Print() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->nextnode;
        } while (current != head); // Ensure we cover all nodes in the circular list

        cout << endl;
    }

    void Reverse(Node*& h) 
	{
        if (h == NULL) return; // Handle empty list

        Node* previous = NULL;
        Node* current = h;
        Node* forward;

        // Reverse the linked list
        while(current != NULL)
        {
        	forward = current->nextnode;
        	current->nextnode = previous;
        	previous = current;
        	current = forward;
		}

        // Update head_ref to the new head
        h = previous;
    }

    Node* middle() 
	{
        if (head == NULL) return NULL;

        Node* slow = head;
        Node* fast = head;

        // Use fast and slow pointers to find the middle
        while (fast != head && fast->nextnode != head) 
		{
            fast = fast->nextnode->nextnode;
            slow = slow->nextnode;
        }
        return slow; // Return middle node
    }

bool Check_Palindrome() {
    // Check for empty or single-node list
    if (head == nullptr || head->nextnode == head) {
        return true;
    }

    // Find the middle of the list
    Node* middle_node = middle();
    if (middle_node == nullptr) return false;

    // Split the list into two halves
    Node* head1 = head;
    Node* head2 = middle_node->nextnode;

    // Break the circularity
    middle_node->nextnode = nullptr;

    // Reverse the second half of the list
    Reverse(head2);

    // Compare the two halves
    Node* temp1 = head1;
    Node* temp2 = head2;
    bool is_palindrome = true;

    while (temp2 != nullptr) {
        if (temp1->data != temp2->data) {
            is_palindrome = false;
            break;
        }
        temp1 = temp1->nextnode;
        temp2 = temp2->nextnode;
    }

    // Restore the second half to its original order
    Reverse(head2);
    middle_node->nextnode = head2; // Reconnect the two halves

    return is_palindrome;
}


};

int main() {
    LinkedList L1;
    L1.Add_CLL(1, 5);
    L1.Add_CLL(2, 0);
    L1.Add_CLL(3, 2);
    L1.Add_CLL(4, 5);


    L1.Print();
    cout << "Is palindrome: " << (L1.Check_Palindrome() ? "Yes" : "No") << endl;

    return 0;
}
