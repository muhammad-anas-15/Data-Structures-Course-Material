#include<iostream>
using namespace std;

void swap(int *p , int *q)
{
	int fact = *p;
	*p = *q;
	*q = fact;
}

int main()
{
	int a = 7, b = 9;
	swap(&a,&b);
	
	cout<<"Value of a :"<<a<<endl;
	cout<<"Value of b :"<<b<<endl;
}