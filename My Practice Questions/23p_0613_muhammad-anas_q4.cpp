#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1; // Initialize stack as empty
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (top < capacity - 1) {
            arr[++top] = value; // Increment top and add value
        }
    }

    int pop() {
        if (!isEmpty()) {
            return arr[top--]; // Return the top value and decrement top
        }
        return -1; // Return -1 if stack is empty
    }

    int peek() {
        if (!isEmpty()) {
            return arr[top]; // Return the top value without removing it
        }
        return -1; // Return -1 if stack is empty
    }
};

int longestValidParentheses(const string &s) {
    Stack stack(s.length());
    int maxLength = 0;
    stack.push(-1); // Base index for valid substring calculation

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stack.push(i); // Push the index of '(' onto the stack
        } else {
            // If it's a closing parenthesis
            stack.pop(); // Remove the last '(' index

            if (stack.isEmpty()) {
                stack.push(i); // Push the index of the unmatched ')'
            } else {
                // Calculate the length of the valid substring
                int length = i - stack.peek();
                maxLength = max(maxLength, length); // Update max length
            }
        }
    }

    return maxLength; // Return the maximum length of valid parentheses
}

int main() {
    string str;
    cout << "Enter a string of parentheses: ";
    getline(cin, str); // Read the input string

    int result = longestValidParentheses(str); // Calculate the result
    cout << "The length of the longest valid parentheses substring is: " << result << endl; // Output the result

    return 0;
}
