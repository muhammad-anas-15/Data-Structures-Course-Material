#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    int coeff;
    int exp;
    Node *next;
};

Node* poly = nullptr;

void create() {
    Node *t, *last = nullptr;
    int num, i;
    cout << "Enter number of terms: ";
    cin >> num;
    cout << "Enter each term with coeff and exp\n";
    for (i = 0; i < num; i++) {
        t = new Node;
        cin >> t->coeff >> t->exp;
        t->next = nullptr;
        if (poly == nullptr) {
            poly = last = t;
        } else {
            last->next = t;
            last = t;
        }
    }
}

void display(Node *p) {
    while (p) {
        cout << p->coeff << "x^" << p->exp;
        if (p->next) {
            cout << " + ";
        }
        p = p->next;
    }
    cout << endl;
}

long eval(Node *p, int x) {
    long val = 0;
    while (p) {
        val += p->coeff * pow(x, p->exp);
        p = p->next;
    }
    return val;
}

int main() {
    create();
    display(poly);
    cout << eval(poly, 1) << endl;
    return 0;
}
