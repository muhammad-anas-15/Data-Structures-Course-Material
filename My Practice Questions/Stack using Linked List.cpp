#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
} *top = NULL;

void push(int x) {
    Node *t = new Node;
    if (t == NULL) {
        cout << "Stack is full" << endl;
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop() {
    Node *t;
    int x = -1;
    if (top == NULL) {
        cout << "Stack is Empty" << endl;
    } else {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void Display() {
    Node *p = top;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    Display();
    cout << pop() << endl;
    return 0;
}
