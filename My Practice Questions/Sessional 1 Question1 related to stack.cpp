#include <iostream>
#include <stack>
using namespace std;

// Function to reverse even or odd values in the stack
void reverseSelected(stack<int>& s, bool even) {
    stack<int> tempStack, auxStack;
    
    // Step 1: Move all elements to a temporary stack
    while (!s.empty()) {
        int val = s.top();
        s.pop();
        tempStack.push(val);
        // Collect even or odd values to be reversed
        if ((even && val % 2 == 0) || (!even && val % 2 != 0)) {
            auxStack.push(val);
        }
    }
    
    // Step 2: Rebuild the original stack with reversed values
    while (!tempStack.empty()) {
        int val = tempStack.top();
        tempStack.pop();
        if ((even && val % 2 == 0) || (!even && val % 2 != 0)) {
            s.push(auxStack.top());
            auxStack.pop();
        } else {
            s.push(val);
        }
    }
}

// Helper function to print the stack
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(8);
    s.push(1);
    s.push(2);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(6);
    s.push(7);

    cout << "Original Stack: ";
    printStack(s);

    reverseSelected(s, true); // Reverse even numbers
    cout << "After reversing evens: ";
    printStack(s);

    reverseSelected(s, false); // Reverse odd numbers
    cout << "After reversing odds: ";
    printStack(s);

    return 0;
}
