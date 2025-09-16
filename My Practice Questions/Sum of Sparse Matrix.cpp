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

struct Sparse* add(struct Sparse *s1, struct Sparse *s2) {
    if (s1->m != s2->m || s1->n != s2->n) {
        cout << "Matrices cannot be added\n";
        return nullptr;
    }

    struct Sparse *sum = new Sparse;
    sum->m = s1->m;
    sum->n = s1->n;
    sum->ele = new Element[s1->num + s2->num];
    
    int i, j, k;
    i = j = k = 0;

    while (i < s1->num && j < s2->num) {
        if (s1->ele[i].i < s2->ele[j].i || (s1->ele[i].i == s2->ele[j].i && s1->ele[i].j < s2->ele[j].j)) {
            sum->ele[k++] = s1->ele[i++];
        } else if (s1->ele[i].i > s2->ele[j].i || (s1->ele[i].i == s2->ele[j].i && s1->ele[i].j > s2->ele[j].j)) {
            sum->ele[k++] = s2->ele[j++];
        } else {
            sum->ele[k] = s1->ele[i];
            sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
        }
    }

    for (; i < s1->num; i++) {
        sum->ele[k++] = s1->ele[i];
    }
    for (; j < s2->num; j++) {
        sum->ele[k++] = s2->ele[j];
    }

    sum->num = k;

    return sum;
}

int main() {
    struct Sparse s1, s2, *s3;

    create(&s1);
    create(&s2);

    s3 = add(&s1, &s2);
    
    if (s3) {
        cout << "First Matrix:\n";
        display(s1);
        cout << "\nSecond Matrix:\n";
        display(s2);
        cout << "\nSum of Matrices:\n";
        display(*s3);
        delete[] s3->ele;
        delete s3;
    }

    delete[] s1.ele;
    delete[] s2.ele;

    return 0;
}
