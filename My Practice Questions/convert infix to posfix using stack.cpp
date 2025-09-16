#include <iostream>
#include <string>
using namespace std;

class Node 
{
public:
    char data;
    Node* next;

    Node(char val) 
    {
        data = val;
        next = NULL;
    } 
};

class Stack 
{
private:
    Node* top;
    int stack_size, current_size; 

public:
    Stack(int s) 
    {
        top = NULL;
        stack_size = s; 
        current_size = 0;
    } 

    ~Stack() 
    {
        while (!isEmpty()) 
        {
            Pop();
        }
    }

    bool isEmpty() 
    {
        return top == NULL;
    }

    bool isFull() 
    {
        return current_size >= stack_size; 
    }        

    void Push(char val) 
    {
        if (isFull()) 
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        Node* newNode = new Node(val); 
        newNode->next = top; 
        
        top = newNode; 
        current_size++; 
    }

    char Pop() 
    {
        if (!isEmpty()) 
        {
            Node* temp = top;
            
            char pop_val = top->data;
            top = top->next;
            
            delete temp;
            current_size--; // Decrement current size after popping
            
            return pop_val;
        } 
        else 
        {
            cout << "Stack underflow" << endl;
            return '\0';
        }
    }

    char Peek() 
    {
        return !isEmpty() ? top->data : '\0'; 
    }

    int checkPrecedence(char operators) 
    {
        switch (operators) 
        {
            case '+':
            case '-':
                return 1;
                
            case '*':
            case '/':
                return 2;
                
            case '^':
                return 3; // Higher precedence for exponentiation
                
            default:
                return 0;
        }
    }

    string infixToPostfix(const string &exp) 
    {
        string postfix;

        for (int i = 0; i < exp.length(); i++) 
        {
            char ch = exp[i];

            // Ignore spaces
            if (ch == ' ') continue;

            // Check if the character is a digit or a letter
            if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) 
            {
                postfix += ch; // Append operands directly
            } 
            
            else if (ch == '(') 
            {
                Push(ch); // Push '(' onto the stack
            } 
            
            else if (ch == ')') 
            {
                while (!isEmpty() && Peek() != '(') 
                {
                    postfix += Pop(); // Append popped operators
                }
                
                if (!isEmpty()) Pop(); // Remove '('
            } 
            else // Operator
            {
                while (!isEmpty() && checkPrecedence(Peek()) >= checkPrecedence(ch)) 
                { 
                    postfix += Pop(); // Append popped operators
                }
                Push(ch); // Push current operator
            }
        }

        while (!isEmpty()) 
        {
            postfix += Pop(); // Append remaining operators
        }   

        return postfix; // Return postfix expression
    }
};

int main() 
{
    string exp;

    cout << "Enter Infix Expression: ";
    getline(cin, exp); // Read the infix expression

    Stack S1(exp.length()); // Create a stack with a size based on the expression length

    string postfix = S1.infixToPostfix(exp); // Convert to postfix
    
    cout << "The Postfix Expression: " << postfix << endl; // Output the postfix expression

    return 0;
}