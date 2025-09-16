#include<iostream>
using namespace std;

class Element{
    public:
        int i, j, x;
};

class Sparse{
    private:
        int m, n, num;
        Element *ele;
        
    public:
        Sparse(int m, int n, int num) {
            this->m = m;
            this->n = n;
            this->num = num;
            ele = new Element[this->num];
        } 
        
        ~Sparse() {
            delete[] ele;
        }
        
        friend istream & operator>>(istream &is, Sparse &s);
        friend ostream & operator<<(ostream &os, Sparse &s);
};
        
        istream & operator>>(istream &is, Sparse &s) 
		{
            cout << "Enter non-zero elements:\n";
            for(int i = 0; i < s.num; i++) {
                cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
            }
            return is;
        }
        
        ostream & operator<<(ostream &os, Sparse &s) {
            int k = 0;
            for(int i = 0; i < s.m; i++) {
                for(int j = 0; j < s.n; j++) {
                    if(k < s.num && s.ele[k].i == i && s.ele[k].j == j) 
                        cout << s.ele[k++].x << " ";
                    else 
                        cout << "0 ";
                }
                cout << endl;
            }
            return os;
        }


int main() {
    Sparse s1(5, 5, 5);
    cin>>s1;
    cout<<s1;
    
    return 0;
}
