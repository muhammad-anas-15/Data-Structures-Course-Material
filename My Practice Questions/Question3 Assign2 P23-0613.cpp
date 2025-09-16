#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    char *arrhead, *top;
    int size;

public:
    Stack(int size) {
        this->size = size;
        arrhead = new char[size];
        top = arrhead - 1; // Start before the first element
    }

    ~Stack() {
        delete[] arrhead;
        top = NULL;
    }

    bool isFull() {
        return top >= arrhead + size - 1;
    }

    bool isEmpty() {
        return top < arrhead;
    }

    void Push(char val) {
        if (!isFull()) {
            top++;
            *top = val;
        } else {
            cout << "Stack Overflow!" << endl;
        }
    }

    void Pop() {
        if (!isEmpty()) {
            top--;
        } else {
            cout << "Stack Underflow!" << endl;
        }
    }

    char Peak() {
        if (!isEmpty()) {
            return *top;
        }
        return '\0'; // Return a null character if stack is empty
    }

    // Function to check operator precedence
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0; // For non-operators
    }

    // Function to convert infix to postfix
    string infixToPostfix(const string &expression) {
        string postfix = "";
        for (int i = 0; i < expression.length(); i++) {
            char ch = expression[i];

            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
                // If the character is an operand (A-Z, a-z, or 0-9)
                postfix += ch; // Append operand to output
            } else if (ch == '(') {
                Push(ch); // Push '(' to stack
            } else if (ch == ')') {
                while (!isEmpty() && Peak() != '(') {
                    postfix += Peak(); // Append top of stack to output
                    Pop();
                }
                Pop(); // Pop the '(' from stack
            } else if (ch != ' ') { // Ignore spaces
                // If the character is an operator
                while (!isEmpty() && precedence(Peak()) >= precedence(ch)) {
                    postfix += Peak(); // Append top of stack to output
                    Pop();
                }
                Push(ch); // Push the current operator onto the stack
            }
        }

        // Pop all the operators from the stack
        while (!isEmpty()) {
            char topChar = Peak();
            if (topChar != '(') { // Only pop if it's not a '('
                postfix += topChar;
            }
            Pop();
        }

        return postfix; // Return the resulting postfix expression
    }
};

int main() {
    Stack S1(100); // Create a stack with a size of 100

    string expression;
    cout << "Enter an infix expression: ";
    getline(cin, expression); // Read the infix expression

    string postfix = S1.infixToPostfix(expression); // Convert to postfix
    cout << "The postfix expression is: " << postfix << endl; // Output the postfix expression

    return 0;
}
