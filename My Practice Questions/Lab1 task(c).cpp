#include<iostream>
using namespace std;

class Teacher 
{
    public:
        string name;
        string subject;
        int experience;
        
        Teacher(string n, string s, int e) {
            name = n;
            subject = s;
            experience = e;
        }
};

class Principal : public Teacher 
{
    public:
        int yearsAsPrincipal;
        
        Principal(string n, string s, int e, int y) : Teacher(n, s, e) 
		{
            yearsAsPrincipal = y;
        }
        
        void display() {
            cout << "Name: " << name << endl;
            cout << "subject: " << subject << endl;
            cout << "experience: " << experience << " years" << endl;
            cout << "years as principal: " << yearsAsPrincipal << " years" << endl;
        }
};

int main() {
    Principal P1("Ali", "Programming", 20, 3);
    P1.display();
    
    return 0;
}
