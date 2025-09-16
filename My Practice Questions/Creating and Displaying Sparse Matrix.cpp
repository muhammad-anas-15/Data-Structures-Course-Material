#include <iostream>
using namespace std;

struct Element {
    int i;
    int j;
    int x;
};

struct Sparse {
    int m;
    int n;
    int num;
    struct Element *ele;
};

void create(struct Sparse *s) {
    cout << "Enter Dimensions: ";
    cin >> s->m >> s->n;
    cout << "Enter number of non-zero elements: ";
    cin >> s->num;

    s->ele = new Element[s->num];
    cout << "Enter non-zero elements (row column value): ";

    for (int i = 0; i < s->num; i++) {
        cin >> s->ele[i].i >> s->ele[i].j >> s->ele[i].x;
    }
}

void display(struct Sparse s) {
    int i, j, k = 0;

    for (i = 0; i < s.m; i++) {
        for (j = 0; j < s.n; j++) {
            if (k < s.num && i == s.ele[k].i && j == s.ele[k].j) {
                cout << s.ele[k++].x << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << "\n";
    }
}

int main() {
    struct Sparse s;

    create(&s);
    display(s);

    delete[] s.ele; // Free the allocated memory
    return 0;
}
