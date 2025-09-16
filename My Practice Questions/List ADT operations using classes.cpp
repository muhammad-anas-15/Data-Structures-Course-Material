#include <iostream>
using namespace std;

class Array {
    private:
       int A[10];
       int size; // size of whole array.
       int length; // no of elements.

    public:
    Array(int arr[], int size, int length)
	 {
        this->size = size;
        this->length = length;
        
        for (int i = 0; i < length; i++) 
		{
            A[i] = arr[i];
        }
    }

    void Display()
	{
        cout << "\nElements are: ";
        for (int i = 0; i < length; i++) 
		{
           cout<<A[i] << " ";
        }
    }

   void isFull()
   {
   	  if(size == length)
   	  {
   	    cout<<"\nFull"<<endl;  	
	  }
   }
   
   void isEmpty()
   {
   	  if(size != length)
   	  {
   	    cout<<"\nEmpty"<<endl;  	
	  }
   }

    void Append(int x) 
	{
        if (length < size) 
		{
            A[length++] = x;// add element at last index.
        }
    }

   int ListSize

    void Insert(int index, int x) // Function to insert an element at a specific index
	{
        if (index >= 0 && index <= length) 
		{
            for (int i = length ; i > index; i--) 
			{
                A[i] = A[i - 1];
            }
            
            A[index] = x;
            length++;
        }
    }
    void Delete(int index) // Function to delete an element at a specific index
	{
        if (index >= 0 && index <= length) 
		{
			int x = A[index];
			
            for (int i = index ; i < length-1; i++) 
			{
                A[i] = A[i + 1];
            }
            length--;
        }
    }
};

int main() 
{
    int arr[] = {2, 3, 4, 5, 6};
    Array arr1(arr, 10, 5);

    //arr1.Append(10);
    
    //arr1.Insert(2, 12);
    //arr1.Delete(3);
    arr1.Display();
    arr1.isFull();// 1 full or 0 empty.
    //arr1.isEmpty();

    return 0;
}
