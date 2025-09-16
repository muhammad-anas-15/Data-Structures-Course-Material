#include <iostream>
#include <string>
#include <cctype> // For isdigit
using namespace std;

class Stack 
{
private:
    int *arrhead, *top;
    int size;

public:
    Stack(int size) 
	{
        this->size = size;
        arrhead = new int[size];
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

    void Push(int val) 
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

    int Peak() 
	{
        if (!isEmpty()) 
		{
            return *top;
        }
        cout << "Stack is Underflow! " << endl;
        return -1; // Return a sentinel value
    }

    int evaluatePostfix(string expression) 
	{
        for (int i = 0; i < expression.length(); i++) 
		{
            char ch = expression[i];

           
            if (ch >= '0' && ch <= '9') 
			{
               
                int num = 0;

                while (i < expression.length() && (expression[i] >= '0' && expression[i] <= '9')) 
				{
                    num = num * 10 + (expression[i] - '0');
                    i++;
                }
                
                Push(num);  
                i--; 
            } 
            
			else if (ch == ' ') 
			{
                continue;
            } 
			else 
			{
                if (isEmpty())  // If it's an operator, pop two elements and apply the operation
				{
                    cout << "Invalid postfix expression!" << endl;
                    return -1; 
                }
                
                int operand2 = Peak();
                Pop();
                
                if (isEmpty()) 
				{
                    cout << "Invalid postfix expression!" << endl;
                    return -1; 
                }
                
                int operand1 = Peak();
                Pop(); 
                
                int result;

                switch (ch) 
				{
                    case '+':
                        result = operand1 + operand2;
                        break;
                        
                    case '-':
                        result = operand1 - operand2;
                        break;
                        
                    case '*':
                        result = operand1 * operand2;
                        break;
                        
                    case '/':
                        if (operand2 != 0) 
						{
                            result = operand1 / operand2;
                        } 
						else 
						{
                            cout << "Division by zero error!" << endl;
                            return -1;
                        }
                        
                        break;
                        
                    default:
                        cout << "Invalid operator encountered: " << ch << endl;
                        return -1;
                }

                Push(result);
            }
        }

        if (isEmpty()) 
		{
            cout << "Invalid postfix expression!" << endl;
            return -1;
        }
        
        return Peak(); 
    }
};

int main() 
{
    Stack S1(100);

    string expression;
    cout << "Enter postfix expression (e.g., 23 4 + 5 *): ";
    getline(cin, expression); 

    int result = S1.evaluatePostfix(expression);
    cout << "The result of the postfix expression is: " << result << endl;

    return 0;
}
