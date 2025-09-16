#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    char data;
    Node *next;
} *top = NULL;

void push(char x) {
    Node *t = new Node;
    if (t == NULL) {
        cout << "Stack is full" << endl;
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop() {
    Node *t;
    char x = -1;
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

bool isBalanced(char *exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            if (top == NULL) return false;
            pop();
        }
    }
    return top == NULL;
}

int main() {
    char exp[] = "((a+b)*(c-d)))";
    cout << isBalanced(exp) << endl;
    return 0;
}
