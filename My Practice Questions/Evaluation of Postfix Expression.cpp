#include <iostream>
#include <cstring>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class Stack {
private:
    Node *top;
public:
    Stack() { top = nullptr; }

    void push(int x);
    int pop();
    void display();
    bool isBalanced(const char *exp);
    int pre(char x);
    bool isOperand(char x);
    char* InToPost(const char *infix);
    int Eval(const char *postfix);
};

void Stack::push(int x) {
    Node *t = new Node;
    if (t == nullptr) {
        cout << "Stack is full" << endl;
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop() {
    Node *t;
    int x = -1;
    if (top == nullptr) {
        cout << "Stack is Empty" << endl;
    } else {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void Stack::display() {
    Node *p = top;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

bool Stack::isBalanced(const char *exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            if (top == nullptr) return false;
            pop();
        }
    }
    return top == nullptr;
}

int Stack::pre(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

bool Stack::isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/') return false;
    return true;
}

char* Stack::InToPost(const char *infix) {
    int i = 0, j = 0;
    int len = strlen(infix);
    char *postfix = new char[len + 2];

    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else {
            while (top != nullptr && pre(infix[i]) <= pre(top->data)) {
                postfix[j++] = pop();
            }
            push(infix[i++]);
        }
    }
    while (top != nullptr) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int Stack::Eval(const char *postfix) {
    int i = 0;
    int x1, x2, r = 0;
    for (i = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i])) {
            push(postfix[i] - '0');
        } else {
            x2 = pop();
            x1 = pop();
            switch (postfix[i]) {
                case '+': r = x1 + x2; break;
                case '-': r = x1 - x2; break;
                case '*': r = x1 * x2; break;
                case '/': r = x1 / x2; break;
            }
            push(r);
        }
    }
    return top->data;
}

int main() {
    const char *postfix = "234*+82/-";
    Stack stk;
    cout << "Result is " << stk.Eval(postfix) << endl;
    return 0;
}
