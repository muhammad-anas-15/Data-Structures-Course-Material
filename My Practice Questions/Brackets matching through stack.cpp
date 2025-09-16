#include <iostream>
#include <string>
using namespace std;

class Stack 
{
private:
    char *arrhead, *top;
    int size;

public:
    Stack(int size) 
	{
        this->size = size;
        arrhead = new char[size];
        top = arrhead - 1; // Start before the first element
    }

    ~Stack() 
	{
        delete[] arrhead;
        top = NULL;
    }

    bool isFull() 
	{
        return top >= arrhead + size - 1;
    }

    bool isEmpty() 
	{
        return top < arrhead;
    }

    void Push(char val) 
	{
        if (!isFull()) 
		{
            top++;
            *top = val;
        } 
		else 
		{
            cout << "Stack Overflow!" << endl;
        }
    }

    void Pop() 
	{
        if (!isEmpty()) 
		{
            top--;
        } 
		else 
		{
            cout << "Stack Underflow!" << endl;
        }
    }

    char Peak()
	{
        if (!isEmpty()) 
		{
            return *top;
        }
        return '\0'; // Return a null character if stack is empty
    }

    // Function to check if the brackets are balanced
    bool isBalanced(const string &expression) 
	{
        for (char ch : expression) 
		{
            if (ch == '(' || ch == '{' || ch == '[') {
                Push(ch);
            } 
			else if (ch == ')' || ch == '}' || ch == ']') 
			{
                if (isEmpty()) 
				{
                    return false; // No opening bracket for the closing one
                }
                
                char topChar = Peak();
                
                if ((ch == ')' && topChar == '(') ||
                    (ch == '}' && topChar == '{') ||
                    (ch == ']' && topChar == '[')) {
                    Pop(); // Matched
                } 
				else 
				{
                    return false; // Mismatched brackets
                }
            }
        }
        return isEmpty(); // If stack is empty, brackets are balanced
    }
};

int main() {
    Stack S1(100); // Create a stack with a size of 100

    string expression;
    cout << "Enter a string with brackets: ";
    getline(cin, expression); // Read the string with brackets

    if (S1.isBalanced(expression)) {
        cout << "The brackets are balanced." << endl;
    } else {
        cout << "The brackets are not balanced." << endl;
    }

    return 0;
}
