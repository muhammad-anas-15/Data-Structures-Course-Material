#include<iostream>
using namespace std;

class ArrayList
{
	private:
		int *head, *current;
		int ListSize, ArraySize;
	
	public:
	     ArrayList(int s)
		 {
		 	 ArraySize = s; 
		 	 head = new int[ArraySize];
		 	 
		 	 ListSize = 0;
		 	 current = NULL;
		 }
		 	
		 ~ArrayList()
		 {
		 	delete[] head;
		 	current = NULL;
		 }
		 
		 void Start()
		 {
		 	current = head;
		 }
		 
		 void Tail()
		 {
		 	current = head + (ListSize - 1);
		 }
		 
		 bool Next()
		 {
		 	int *temp = head + (ListSize - 1);
		 	
		 	if(current == temp) return false;
		 	
		 	current++; 
		 	temp = NULL;  
			return true;  
		 }
		 
		 bool Back()
		 {
		 	if(current = head) return false;
		 	
		 	current--;
		 	return true;
		 }
		   
		 int Getsize()
		 {
		 	return ListSize;
		 }
		 
		 bool isEmpty()
		 {
		 	if(ListSize == 0)
		 	{
		 		return true;
			 }
			 return false;
		 }
		 
		 bool isFull()
		 {
		 	if(ListSize == ArraySize)
		 	{
		 		return true;
			}
			 return false;
		 }
		 
		 void PrintList()
		 {
		 	if(!isEmpty())
		 	{
			   	Start();
			   	
		 	for(int i= 0; i< ListSize; i++)
		 	{
		 		cout<<*current<<" ";
		 		Next();
			 }
			}
			
			cout<<"List is Empty"<<endl;
		 
		 }
		 
		 int Search(int val)
		 {
		 	if(!isEmpty())
		 	{
			   	Start();
			   	
		 	for(int i= 0; i< ListSize; i++)
		 	{
		 		if(*current  == val)
		 		{
		 			return *current;
				 }
		 		Next();
			 }
			}
			else
			{
				cout<<"Not Found!";
			}
		 }
		 
		 void Remove()
		 {
		 	Tail();
		 	ListSize--;
		 	Back();
		 }
		 
		 void Add(int val)
		 {
		 	if(!isFull())
		 	{
		 		Tail();
		 		* (current + 1) = val;
		 		ListSize++;
		 		Next();
			 }
			 else
			 {
			 	cout<<"List is Full";
			 }
		 }
		 
		 int Search_Position(int pos)
		 {
		 	if(pos <0 || pos> ListSize - 1)
		 	{
		 	  cout<<"Invalid Position";
			   return -1;	
			 }
			 else if(!isEmpty())
			 {
			 	return -1;
			 	
			 }
			 else
			 
		 	{
			   	current = head + pos;
			   	cout<<"Position found"<<endl;
			   	return *current;
		 }
	}
	
	int Addpos(int pos, int val)
	{
		if(pos <0 || pos >ListSize - 1) return -1;
		
		else if(isEmpty()) return -1;
		
		else
		{
			Tail();
			
			for(int i = ListSize; i>pos; i--)
			{
				head [i] =  head [i-1];
			}
			
			head[pos] = val;
			ListSize++;
			 
			Next();
		}	      
	}
	
	int Removepos(int pos)
	{
		if(pos <0 || pos >ListSize - 1) return -1;
		else if(isEmpty()) return -1;
		
		else
		{
			Tail();
			
			for(int i= ListSize; i>pos; i--)
			{
				head [i] =  head [i+1];
			}
			
			ListSize--;
			Back();
		}	      
	}
};


int main()
{
	ArrayList A1(10);
	
	A1.Add(2);
	A1.Add(1);
	A1.Add(3);
	A1.Add(7);
	
	A1.Start();
	A1.Tail();
	A1.Next();
	A1.Back();
	
	cout<<A1.Getsize()<<endl;
	
	A1.isEmpty();
	A1.isFull();
	
	A1.PrintList();
	
	cout<<A1.Search(9)<<endl;
	
	A1.Remove();
	
	A1.PrintList();
	
	cout<<A1.Search_Position(2)<<endl;
	
	A1.Addpos(2, 10);
	
	A1.PrintList();
	
	A1.Removepos(3);
	
	A1.PrintList();
}