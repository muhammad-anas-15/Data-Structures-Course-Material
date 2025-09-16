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

bool isBalanced(const char *exp) {
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

int pre(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

bool isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/') return false;
    return true;
}

char *InToPost(const char *infix) {
    int i = 0, j = 0;
    int len = strlen(infix);
    char *postfix = new char[len + 2];

    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else {
            if (pre(infix[i]) > pre(top->data)) {
                push(infix[i++]);
            } else {
                postfix[j++] = pop();
            }
        }
    }
    while (top != NULL) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main() {
    const char *infix = "a+b*c-d/e";
    push('#');  // Sentinel to avoid null pointer dereference
    char *postfix = InToPost(infix);
    cout << postfix << endl;
    delete[] postfix;  // Clean up the allocated memory
    return 0;
}
