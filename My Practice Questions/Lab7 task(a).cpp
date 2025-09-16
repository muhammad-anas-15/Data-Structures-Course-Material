#include<iostream>
#include<string>
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
            top = arrhead - 1; 
        }

        ~Stack() {
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

        char Pop() 
        {
            if (!isEmpty()) 
            {
                char temp = *top;
                top--;
                return temp;
            } 
            else 
            {
                cout << "Stack Underflow!" << endl;
                return '\n'; 
            }
        }
};

string reverse_str(string alp) 
{
    int n = alp.length();
    Stack S1(n);  
    
    for (int i = 0; i < n; i++) 
    {
        S1.Push(alp[i]);
    }

    string rev = "";
    while (!S1.isEmpty()) 
    {
        rev += S1.Pop();
    }

    return rev; 
}

int main() 
{
    string i;
    cout << "Enter a string: ";
    getline(cin, i);  

    string reversed = reverse_str(i);  

    cout << "Reversed string: " << reversed << endl;  

    return 0;
}
