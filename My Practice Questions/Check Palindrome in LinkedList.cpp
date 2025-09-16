#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node *nextnode;
    
    Node(int val) : data(val), nextnode(NULL) {}
};

class LinkedList 
{
private:
    Node *head;
    Node *current;
    int List_Size;

public:
    LinkedList() : head(NULL), current(NULL), List_Size(0) {}
    
    void Add_End(int val) 
	{
        Node *newnode = new Node(val);
        
        if (head == NULL) 
		{
            head = current = newnode;
        } 
		else 
		{
            current->nextnode = newnode;
            current = newnode;
        }
        List_Size++;
    }
    
    void Print() 
	{
        current = head;
        
        while (current != NULL) 
		{
            cout << current->data << " ";
            current = current->nextnode;
        }
        cout << endl;
    }
    
    void Reverse(Node *&head_ref) 
    {
        Node *previous = NULL;
        Node *forward = NULL;
        current = head_ref;
        
        while (current != NULL) 
		{
            forward = current->nextnode;
            current->nextnode = previous;
            previous = current;
            current = forward;
        }
        head_ref = previous;
    }
    
    Node* middle() 
    {
        if (head == NULL) return NULL;
        
        Node *temp1 = head;
        Node *temp2 = head;
        
        while (temp2 != NULL && temp2->nextnode != NULL) 
        {
            temp2 = temp2->nextnode->nextnode;
            temp1 = temp1->nextnode;
        }
        return temp1;
    }
    
    bool Check_Palindrome() 
    {
        if (head == NULL || head->nextnode == NULL) 
		{
            return true;
        }
        
        // Find the middle of the list
        Node *middle_node = middle();
        
        if (middle_node == NULL) return false;

        // Split the list into two halves
        Node *head1 = head;
        Node *head2 = middle_node->nextnode;
        
        middle_node->nextnode = NULL; // Split the list
        
        // Reverse the second half of the list
        Reverse(head2);

        // Compare the two halves
        Node *temp1 = head1;
        Node *temp2 = head2;
        
        while (temp2 != NULL) 
        {
            if (temp1->data != temp2->data) 
            {
                // Restore the second half to its original order before returning
                Reverse(head2);
                
                middle_node->nextnode = head2; // Reconnect the two halves
                return false;
            }
            
            temp1 = temp1->nextnode;
            temp2 = temp2->nextnode;
        }
        
        // Restore the second half to its original order
        Reverse(head2);
        middle_node->nextnode = head2; // Reconnect the two halves
        
        return true;
    }
};

int main() {
    LinkedList L1;
    L1.Add_End(1);
    L1.Add_End(2);
    L1.Add_End(3);
    L1.Add_End(5);
    L1.Add_End(1);

    L1.Print();
    cout << "Is palindrome: " << (L1.Check_Palindrome() ? "Yes" : "No") << endl;
    //L1.Print();

    return 0;
}
