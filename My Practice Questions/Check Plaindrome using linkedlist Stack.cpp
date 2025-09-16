#include <iostream>
#include <string>
using namespace std;

class Node 
{
public:
    char data;
    Node* nextnode;

    Node(char val) 
	{
        data = val;
        nextnode = NULL;
    }
};

class Stack 
{
private:
    Node* top;

public:
    Stack() 
	{
        top = NULL;
    }

    void Push(char val) 
	{
        Node* newnode = new Node(val);
        newnode->nextnode = top; 
        top = newnode;           
    }

    char Pop() 
	{
        if (top == NULL) 
		{
            cout << "Stack Underflow!" << endl;
            return '\0'; 
        }
        char poppedValue = top->data;
        Node* temp = top; 
        top = top->nextnode; 
        
        delete temp; 
        
        return poppedValue;
    }

    bool isEmpty() 
	{
        return top == NULL;
    }
};

bool isPalindrome(Stack& stack, const string& str) 
{
    int length = str.length();
    Stack tempStack; // Temporary stack for comparison

    // Push all characters onto the temporary stack
    for (int i = 0; i < length; i++) 
	{
        tempStack.Push(str[i]);
    }

    // Compare elements
    for (int i = 0; i < length; i++) 
	{
        char stackChar = stack.Pop(); // Pop from original stack
        
        char tempChar = tempStack.Pop(); // Pop from temp stack

        if (stackChar != tempChar) 
		{
            return false; // Not a palindrome if mismatch
        }
    }
    return true; // If all characters match, it is a palindrome
}

int main() {
    Stack stack;

    // Push characters onto the stack
    stack.Push('a');
    stack.Push('b');
    stack.Push('c');
    stack.Push('b');
    stack.Push('d');

    // Check if the contents of the stack form a palindrome
    if (isPalindrome(stack, "abcba")) {
        cout << "The stack is a palindrome." << endl;
    } else {
        cout << "The stack is not a palindrome." << endl;
    }

    return 0;
}
