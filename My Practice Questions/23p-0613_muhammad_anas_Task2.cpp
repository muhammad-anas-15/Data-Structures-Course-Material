#include <iostream>
using namespace std;

class ListArray // class to define list array
{
	private:
	    int *headptr, *currentptr; //pointers to traverse in List array.
	    int List_Size, Array_Size; 

	public:
	    ListArray(int Array_Size)  //parametrized constructor to accept arraysize
	    {
	        this->Array_Size = Array_Size;
	        headptr = new int[Array_Size]; //dynamically allocating head pointer to start of list.
	        List_Size = 0;
	        currentptr = headptr; //also current is pointing to start
	    }

	    ~ListArray()  //destructor of deleting dynamically allocated memory for pointer
	    {
	        delete[] headptr;
	        currentptr = NULL;
	    }

	    void Start() // Reset the current pointer to the start of the list
	    {
	        currentptr = headptr;
	    }

	    void Tail() // Set the current pointer to the end of the list
	    {
	        currentptr = headptr + (List_Size - 1);
	    }

	    bool Next() // Move the current pointer to the next position
	    {
	        int *temp = headptr + (List_Size - 1);
	        if (currentptr == temp) 
	            return false;
	        else   
	        {
	            currentptr++;
	            return true;  
	        }
	    }

	    bool Back() // Move the current pointer to the previous position
	    {
	        if (currentptr == headptr) 
	            return false;
	        else   
	        {
	            currentptr--;
	            return true;
	        }
	    }

	    int GetSize() // Return the current size of the list
	    {
	        return List_Size;
	    }

	    bool isEmpty() // Check if the list is empty
	    {
	        return List_Size == 0;
	    }

	    bool isFull() // Check if the list is full
	    {
	        return List_Size == Array_Size;
	    }

	    void PrintList() // Print the elements of the list
	    {
	        if (!isEmpty()) 
	        {
	            Start();
	            for (int i = 0; i < List_Size; i++) 
	            {
	                cout<<*currentptr<< " ";
	                Next();
	            }
	            cout << endl;
	        } 
	        else 
	        {
	            cout << "List is Empty" << endl;
	        }
	    }

	    void Add(int value) // Add a value to the end of the list
	    {
	        if (!isFull()) 
	        {
	            if (List_Size == 0) 
	            {
	                Start();
	                *currentptr = value; 
	            } 
	            else 
	            {
	                Tail();
	                *(currentptr + 1) = value; 
	            }
	            List_Size++;
	        } 
	        else 
	        {
	            cout << "List is Full" << endl;
	        }
	    }

    void Remove() // Remove a value at the current position in the list
    {
        if (!isEmpty()) 
        {
            int index = currentptr - headptr;  // store index of the current position
            
            
            for (int i = index; i < List_Size - 1; i++) // loop for shifting 
            {
                headptr[i] = headptr[i + 1]; // move next element to the current index.
            }

            List_Size--; 
            
            
            if (index >= List_Size) // If current index is out of Listsize then reset the current pointer to the start.
            {
                Start();  // Reset current pointer to the start of the list
            }
            else 
            {
                currentptr = headptr + index;  // Update the current pointer to the correct position
            }
        }
    }

    int Josephus(int k)  // Function definition for Josepehus problem
    {
        Start();  // Reset current pointer to the start of the list
        
        int temp = List_Size;  //store the length of list in temp variable

        
        while (temp > 1) // Loop will terate until one person is left in List.
        {
            
            for (int i = 1; i < k; i++) // Loop for moving k-1 positions forward.
            {
                if (!Next())  // condition check if we reached at end of list then reset to the start.
                { 
                    Start();  
                }
            }

            // Eliminate the current person (k-th person)
            cout << "Eliminates the Person: " << *currentptr << endl;
            
            Remove();  // Calling remove function to remove current person.
            
            temp--;  // Decrease the remaining person count
        }

        return *headptr;  // The function will return last remaining person which will be stored in head pointer.
    }

};

int main() 
{

    ListArray A1(7);

    //Calling add function to insert in List
    A1.Add(1);
    A1.Add(2);
    A1.Add(3);
    A1.Add(4);
    A1.Add(5);
    A1.Add(6);
    A1.Add(7);

    cout << "Initial List: ";
    A1.PrintList(); // function to print initial list

    int k = 3; // The number of people to skip before eliminating the next person.
     
    cout<<"\n\n";
    int last = A1.Josephus(k); // calling function and storing Last person in Variable.
    cout<<"\n\n";
    cout << "The last person standing is: " << last << endl;


    return 0;
}
