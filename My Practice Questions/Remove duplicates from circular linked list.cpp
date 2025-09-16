#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *nextnode;

    Node(int d) {
        data = d;
        nextnode = NULL;
    }
};

class LinkedList {
private:
    Node *current, *head;
    int List_size;

public:
    LinkedList() {
        current = head = NULL;
        List_size = 0;
    }

    void Add_CLL(int pos, int val) {
        if (pos < 1 || pos > List_size + 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node *newnode = new Node(val);

        // Case 1: If the list is empty
        if (head == NULL) {
            head = newnode;
            newnode->nextnode = head; // Circular reference to itself
        } else if (pos == 1) { // Case 2: Insertion at the beginning
            newnode->nextnode = head;
            current = head;

            while (current->nextnode != head) { // Traverse to the last node
                current = current->nextnode;
            }
            current->nextnode = newnode; // Last node points to the new head
            head = newnode; // Update head
        } else { // Case 3: Insertion at a position other than the first
            current = head;

            for (int i = 1; i < pos - 1; i++) { // Traverse to the (pos-1) node
                current = current->nextnode;
            }
            newnode->nextnode = current->nextnode; // Set new node's next to the current node's next
            current->nextnode = newnode; // Link current node to the new node
        }
        List_size++; // Increment list size
    }

    void Print() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        current = head;
        do {
            cout << current->data << " ";
            current = current->nextnode;
        } while (current != head); // Ensure we cover all nodes in the circular list
        
        cout << endl;
    }
    
    void Remove_duplicates_Sorted() 
	{
        if (head == NULL) return; // Handle empty list

        Node *current = head;
        
        do 
		{
            if (current->nextnode != head && current->data == current->nextnode->data) 
			{
                Node *node_to_delete = current->nextnode; // Node to be deleted
                current->nextnode = node_to_delete->nextnode; // Bypass the duplicate
                delete node_to_delete; // Delete the duplicate
            } 
			else
			{
                current = current->nextnode; // Move to the next node
            }
            
        } 
		while (current != head); // Continue until we loop back to head
    }

    void Remove_duplicates_UnSorted() 
	{
        if (head == nullptr) return; // Handle empty list

        Node *current = head;

        do {
            Node *temp = current;
            
            while (temp->nextnode != head) 
			{
                if (current->data == temp->nextnode->data) 
				{
                    // Duplicate found, remove the node
                    Node *node_to_delete = temp->nextnode;
                    temp->nextnode = temp->nextnode->nextnode; // Bypass the duplicate
                    delete node_to_delete; // Delete the duplicate
                } 
				else 
				{
                    temp = temp->nextnode; // Move to the next node only if no deletion happens
                }
            }
            current = current->nextnode; // Move to the next node in the outer loop
        } while (current != head); // Continue until we loop back to head
    }
};

int main() {
    LinkedList L1;
    L1.Add_CLL(1, 5);
    L1.Add_CLL(2, 2);
    L1.Add_CLL(3, 2);
    L1.Add_CLL(4, 1);
    L1.Add_CLL(5, 1); // This should create a palindrome
    L1.Print();

    L1.Remove_duplicates_UnSorted(); // Test unsorted duplicate removal
    cout << "After removing duplicates (unsorted): ";
    L1.Print();

    return 0;
}
