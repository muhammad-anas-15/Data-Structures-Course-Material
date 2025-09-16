#include <iostream>
using namespace std;

struct Term {
    int coeff;
    int exp;
};

struct Poly {
    int n;
    Term *terms;
};

void create(Poly &p) {
    cout << "Number of terms? ";
    cin >> p.n;
    p.terms = new Term[p.n];
    cout << "Enter terms (coefficient and exponent):\n";
    for (int i = 0; i < p.n; i++) {
        cin >> p.terms[i].coeff >> p.terms[i].exp;
    }
}

void display(const Poly &p) {
    for (int i = 0; i < p.n; i++) {
        cout << p.terms[i].coeff << "x^" << p.terms[i].exp;
        if (i != p.n - 1) {
            cout << " + ";
        }
    }
    cout << endl;
}

Poly* add(const Poly &p1, const Poly &p2) {
    int i = 0, j = 0, k = 0;
    Poly *sum = new Poly;
    sum->terms = new Term[p1.n + p2.n];

    while (i < p1.n && j < p2.n) {
        if (p1.terms[i].exp > p2.terms[j].exp) {
            sum->terms[k++] = p1.terms[i++];
        } else if (p1.terms[i].exp < p2.terms[j].exp) {
            sum->terms[k++] = p2.terms[j++];
        } else {
            sum->terms[k].exp = p1.terms[i].exp;
            sum->terms[k++].coeff = p1.terms[i].coeff + p2.terms[j].coeff;
            i++;
            j++;
        }
    }

    for (; i < p1.n; i++) {
        sum->terms[k++] = p1.terms[i];
    }

    for (; j < p2.n; j++) {
        sum->terms[k++] = p2.terms[j];
    }

    sum->n = k;
    return sum;
}

int main() {
    Poly p1, p2, *p3;
    create(p1);
    create(p2);
    p3 = add(p1, p2);

    cout << "First polynomial: ";
    display(p1);
    cout << "Second polynomial: ";
    display(p2);
    cout << "Sum of polynomials: ";
    display(*p3);

    // Free allocated memory
    delete[] p1.terms;
    delete[] p2.terms;
    delete[] p3->terms;
    delete p3;

    return 0;
}
