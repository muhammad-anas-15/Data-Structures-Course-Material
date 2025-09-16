#include<iostream>
using namespace std;

class Student{
	
	public:
		string name;
		int rollno;
		char grade;
		
		Student(string n, int r, char g){
			name = n;
			rollno = r;
			grade = g;
		}
		
	void UpdateGrade()
	{
		cout << "Enter new grade: ";
		cin >> grade;
	}
	void display()
	{
		cout << "Name: " << name << endl;
		cout << "Roll No: " << rollno << endl;
		cout << "Grade: " << grade << endl;
	}
};

int main()
{
	Student S1("Anas", 613, 'B'); 
	S1.display();
	S1.UpdateGrade();
	S1.display();
	
	return 0; 
}
