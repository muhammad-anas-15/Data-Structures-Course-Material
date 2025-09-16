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

public:
    LinkedList() : head(NULL) {}

    void Add_End(int val) 
    {
        Node *newnode = new Node(val);
        if (head == NULL) 
        {
            head = newnode;
        } 
        else 
        {
            Node *temp = head;
            while (temp->nextnode != NULL) 
            {
                temp = temp->nextnode;
            }
            temp->nextnode = newnode;
        }
    }

    void Print() 
    {
        Node *current = head;
        
        while (current != NULL) 
        {
            cout << current->data << " ";
            current = current->nextnode;
        }
        cout << endl;
    }

    bool isPalindromeRecursive(Node *&left, Node *right)  
    {
        if (right == NULL) 
        {
            return true;
        }

        bool isPalin = isPalindromeRecursive(left, right->nextnode);
        
        
        if (!isPalin) 
        {
            return false;
        }

        
        bool isSame = (left->data == right->data);
        
        left = left->nextnode; 

        return isSame; 
    }

    bool Check_Palindrome() 
    {
        //Node *left = head; 
        
        return isPalindromeRecursive(head, head);
    }
};

int main() {
    LinkedList L1;
    L1.Add_End(1);
    L1.Add_End(2);
    L1.Add_End(3);
    L1.Add_End(2);
    L1.Add_End(1); // Odd case: 1 <-> 2 <-> 3 <-> 2 <-> 1

    L1.Print();
    cout << "Is palindrome: " << (L1.Check_Palindrome() ? "Yes" : "No") << endl;

    LinkedList L2;
    L2.Add_End(1);
    L2.Add_End(2);
    L2.Add_End(2);
    L2.Add_End(1); // Even case: 1 <-> 2 <-> 2 <-> 1

    L2.Print();
    cout << "Is palindrome: " << (L2.Check_Palindrome() ? "Yes" : "No") << endl;

    return 0;
}
