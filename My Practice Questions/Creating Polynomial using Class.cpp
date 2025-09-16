#include <iostream>
using namespace std;

class Term {
public:
    int coeff;
    int exp;
};

class Poly {
private:
    int n;
    Term* terms;

public:
    Poly(int n = 0) : n(n) {
        terms = new Term[this->n];
    }

    ~Poly() {
        delete[] terms;
    }

    void create() {
        cout << "Number of terms? ";
        cin >> n;
        terms = new Term[n];
        cout << "Enter terms (coeff exp):" << endl;
        for (int i = 0; i < n; i++) {
            cin >> terms[i].coeff >> terms[i].exp;
        }
    }

    void display() const {
        for (int i = 0; i < n; i++) {
            cout << terms[i].coeff << "x^" << terms[i].exp;
            if (i != n - 1) cout << " + ";
        }
        cout << endl;
    }

    Poly* add(const Poly& p) const {
        int i = 0, j = 0, k = 0;
        Poly* sum = new Poly(n + p.n);

        while (i < n && j < p.n) {
            if (terms[i].exp > p.terms[j].exp)
                sum->terms[k++] = terms[i++];
            else if (terms[i].exp < p.terms[j].exp)
                sum->terms[k++] = p.terms[j++];
            else {
                sum->terms[k].exp = terms[i].exp;
                sum->terms[k++].coeff = terms[i++].coeff + p.terms[j++].coeff;
            }
        }

        for (; i < n; i++) sum->terms[k++] = terms[i];
        for (; j < p.n; j++) sum->terms[k++] = p.terms[j];
        sum->n = k;

        return sum;
    }
};

int main() {
    Poly p1, p2;
    p1.create();
    p2.create();

    Poly* p3 = p1.add(p2);

    cout << "First Polynomial: ";
    p1.display();
    cout << "Second Polynomial: ";
    p2.display();
    cout << "Sum Polynomial: ";
    p3->display();

    delete p3; // Free the dynamically allocated memory

    return 0;
}
