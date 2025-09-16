#include<iostream>
using namespace std;

int main()
{
	int size;
	cout<<"Enter Size: ";
	cin>>size;
	
	int *p= new int[size];
	
	cout<<"Enter value in array: ";
	for(int i=0; i<size; i++)
	{
		cin>>p[i];
	}
	cout<<endl<<endl;
	
	cout<<"Values are: ";
	for(int i=0; i<size; i++)
	{
		cout<<p[i]<< " ";
	}
	delete[] p;
	
}