#include <bits/stdc++.h>
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
            current_size--; 
            return pop_val;
        } 
        else 
        {
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
                return 3;
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

            if (ch == ' ') continue;

            if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) 
            {
                postfix += ch; 
            } 
            else if (ch == '(') 
            {
                Push(ch); 
            } 
            else if (ch == ')') 
            {
                while (!isEmpty() && Peek() != '(') 
                {
                    postfix += Pop(); 
                }
                if (!isEmpty()) Pop(); 
            } 
            else 
            {
                while (!isEmpty() && checkPrecedence(Peek()) >= checkPrecedence(ch)) 
                { 
                    postfix += Pop(); 
                }
                Push(ch); 
            }
        }

        while (!isEmpty()) 
        {
            postfix += Pop(); 
        }   

        return postfix; 
    }
};

int main() 
{
    int t;
    cin >> t;
    cin.ignore(); // Handle newline character after reading t

    while(t--)
    {
        string exp;
        getline(cin, exp);

        Stack S1(exp.length()); 

        string postfix = S1.infixToPostfix(exp); 
        
        cout << postfix << endl; // Output the postfix expression
    }
    return 0;
}
