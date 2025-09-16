#include <iostream>
using namespace std;

struct Stack {
    int size;
    int top;
    int *S;
};

void create(Stack &st) {
    cout << "Enter Size: ";
    cin >> st.size;
    st.top = -1;
    st.S = new int[st.size];
}

void display(const Stack &st) {
    for (int i = st.top; i >= 0; i--)
        cout << st.S[i] << " ";
    cout << endl;
}

void push(Stack &st, int x) {
    if (st.top == st.size - 1) {
        cout << "Stack overflow\n";
    } else {
        st.S[++st.top] = x;
    }
}

int pop(Stack &st) {
    if (st.top == -1) {
        cout << "Stack Underflow\n";
        return -1;
    } else {
        return st.S[st.top--];
    }
}

int peek(const Stack &st, int index) {
    int x = -1;
    if (st.top - index + 1 < 0) {
        cout << "Invalid Index\n";
    } else {
        x = st.S[st.top - index + 1];
    }
    return x;
}

bool isEmpty(const Stack &st) {
    return st.top == -1;
}

bool isFull(const Stack &st) {
    return st.top == st.size - 1;
}

int stackTop(const Stack &st) {
    if (st.top == -1) {
        return -1;
    } else {
        return st.S[st.top];
    }
}

int main() {
    Stack st;
    create(st);
    push(st, 10);
    push(st, 20);
    push(st, 30);
    push(st, 40);
    cout << "Peek at index 2: " << peek(st, 2) << endl;
    display(st);
    
    // Clean up allocated memory
    delete[] st.S;

    return 0;
}
