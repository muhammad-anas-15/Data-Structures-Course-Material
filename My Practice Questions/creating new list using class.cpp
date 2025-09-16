#include<iostream>
using namespace std;

class List
{
	public:
		int *A;
		int size, length;
};

void display(int arr[],int l)
{
	cout<<"list elements are: ";
	
	for(int i = 0; i<l; i++)
	{
		cout<<arr[i]<<" ";
	}
	
}
void clear(int arr[],int l)
{
	delete[] arr;
}

void insert(int arr[],int l, int index, int ele)
{
	if(index >=0 && index <=l)
	{
		for(int i = l; i>index; i--)
		{
			arr[i] = arr[i-1]; 
		}
		arr[index] = ele;
		l++;
	}
}

void Delete(int arr[],int l, int index)
{
	if(index >=0 && index <=l)
	{
		int x = arr[index];
		for(int i = l; i>index; i--)
		{
			arr[i] = arr[i+1]; 
		}
		l--;
	}
}
int Get(int arr[],int l, int index)
{
	if(index >=0 && index <=l)
	{
		int x = arr[index];
		return x;
	}
}
void isFull()
{
	
}

int main()
{
	List L1 ,L2;
	cout<<"Enter size of List: ";
	cin>>L1.size;
	
	L1.A = new int [L1.size];
	L1.length = 0;
	
	int n;
	cout<<"Enter number of numbers: ";
	cin>>n;
	
	cout<<"Enter number of elements\n";
	for(int i =0; i<n; i++)
	{
		cin>>L1.A[i];
	}
	L1.length = n;
	
	L2 = L1; //set one list to be a copy of another
	
	display(L1.A, L1.length);
	cout<<"\n\n";
	
	display(L2.A, L2.length);
	clear(L1.A, L1.length) ;
	insert(L1.A, L1.length, 4, 67);
	Delete(L1.A, L1.length,2);
	
	display(L1.A, L1.length);
	cout<<Get(L1.A, L1.length, 3);
}