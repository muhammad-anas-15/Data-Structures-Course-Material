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
            if(!isFull())
            {
                top++;
                *top = val;
            }
            else
            {
                cout << "Stack Overflow!" << endl;
            }
        }

        char Pop()
        {
            if(!isEmpty())
            {
                char poppedValue = *top;
                top--;
                return poppedValue;
            }
            else
            {
                cout << "Stack Underflow!" << endl;
                return '\0'; // Return a null character as sentinel
            }
        }
};

bool isPalindrome(const string& str)
{
    int length = str.length();
    
    Stack stack(length / 2); // Stack for storing half of the string

    // Push first half of the string onto the stack
    for(int i = 0; i < length / 2; i++)
    {
        stack.Push(str[i]);
    }

    // Calculate starting index for the second half
    int startIndex = (length % 2 == 0) ? length / 2 : (length / 2) + 1;

    // Compare second half with the stack
    for(int i = startIndex; i < length; i++)
    {
        char topChar = stack.Pop();

        // If characters do not match, it's not a palindrome
        if(topChar != str[i])
        {
            return false;
        }
    }

    return true; // If all characters matched, it's a palindrome
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if(isPalindrome(str))
    {
        cout << "The string is a palindrome." << endl;
    }
    else
    {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
