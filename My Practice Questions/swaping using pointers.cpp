#include<iostream>
using namespace std;

void swap(	int *ptr1, int *ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

int main()
{
	int a = 9;
	int b = 10;
	
	swap(a, b);
		cout<<a<<" "<<b<<endl;
 }