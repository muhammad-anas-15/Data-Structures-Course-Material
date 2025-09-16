#include <iostream>
using namespace std;

void palindrome(string  &a) {

    string revers = a;
    int len = revers.length();
    
    
    for (int i = 0; i < len / 2; ++i) 
	{
        revers[i] = revers[i-1];
    }
    
    
    if (a == revers) 
	{
        cout << "\nString is Palindrome!";
    } 
	else
	 {
        cout << "\nString is not Palindrome!";
    }
}

int frequency(string  &a , char &c)
{
  int count = 0;
  int len = a.length();
  	
  for(int i= 0; i<len; i++)
  {
    if(a[i] == c)
	{
	    count++;	
	}	
  }	
  return count;
}
int main() {
    string A;
    cout << "Enter string without spaces: ";
    getline(cin, A);
   
    palindrome(A);
    cout<<"\n\n";
    char freq;
    cout<<"Enter Character which frequency is to check: ";
    cin>>freq;
    
    cout<<"Occurence of char is : "<<frequency(A , freq)<<endl;
    
    return 0;
}