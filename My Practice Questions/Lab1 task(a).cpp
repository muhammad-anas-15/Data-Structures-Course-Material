#include<iostream>
using namespace std;

class Student{
	
	public:
		string name;
		int rollno;
		char grade;
		
	void input()
	{
		cout<<"Enter name: ";
		cin>>name;
		cout<<"Enter rollno: ";
		cin>>rollno;
		cout<<"Enter grade: ";
		cin>>grade;
	}
	void display()
	{
		cout<<"Name: "<<name<<endl;
		cout<<"Roll No: "<<rollno<<endl;
		cout<<"Grade: "<<grade<<endl;
	}
};
int main()
{
	Student S1;
	S1.input();
	S1.display();
}