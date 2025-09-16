#include <iostream>
using namespace std;

class ListArray 
{
private:
    int *headptr, *currentptr;
    int List_Size, Array_Size;

public:
    
    ListArray(int Array_Size)  // Parametrized constructor to initialize the list
    {
        this->Array_Size = Array_Size;
        headptr = new int[Array_Size];
        List_Size = 0;
        currentptr = headptr;
    }

    
    ~ListArray()  // Destructor to clean up dynamically allocated memory
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
        if (!isEmpty()) 
        {
            currentptr = headptr + (List_Size - 1);
        }
    }

   
    bool Next()  // Move the current pointer to the next position
    {
        if (currentptr < headptr + (List_Size - 1)) 
        {
            currentptr++;
            return true;
        }
        return false;
    }

    
    bool Back() // Move the current pointer to the previous position
    {
        if (currentptr > headptr) 
        {
            currentptr--;
            return true;
        }
        return false;
    }

    
    int ListSize() // Return the current size of the list
    {
        return List_Size;
    }

    
    int maxListSize() // Return the maximum size of the list
    {
        return Array_Size;
    }

    
    int Get(int pos)  // Get value at specific position
    {
        if (!isEmpty() && pos >= 0 && pos < List_Size) 
        {
            Start(); // Set current pointer to the start
            for (int i = 0; i < pos; i++) 
            {
                Next(); // Move to the specified position
            }
            return *currentptr;
        } 
        else 
        {
            cout << "Invalid position or list is empty." << endl;
            return 0; 
        }
    }

    
    bool isFull() // Check if the list is full
    {
        return List_Size == Array_Size;
    }

    
    bool isEmpty() // Check if the list is empty
    {
        return List_Size == 0;
    }

    
    void Print() // Print the elements of the list
    {
        if (!isEmpty()) 
        {
            Start();
            for (int i = 0; i < List_Size; i++) 
            {
                cout << *currentptr << " ";
                Next();
            }
            cout << endl;
        } 
        else 
        {
            cout << "List is Empty" << endl;
        }
    }

    
    void Add(int value)  // Add a value to the end of the list
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

    
    void Remove() // Remove the last element from the list
    {
        if (!isEmpty()) 
        {
            Tail(); // Set current pointer to last element
            List_Size--; // Decrease size of the list
            if (List_Size > 0) 
            {
                Back(); // Move current pointer to the new last element
            }
        }
    }

    
    void clear() // Clear all elements from the list
    {
        List_Size = 0;
        Start(); // Reset current pointer to the start
    }

   
    void Update(int pos, int value)   // Update value at a specific position
    {
        if (!isEmpty() && pos >= 0 && pos < List_Size) 
        {
            Start(); // Set current pointer to the start
            for (int i = 0; i < pos; i++) 
            {
                Next(); // Move to the specified position
            }
            *currentptr = value; // Update the value at the current position
        } 
        else 
        {
            cout << "Invalid position or list is empty." << endl;
        }
    }

    
    int Length() // Get length of the list
    {
        return ListSize();
    }
};

int main() 
{
    ListArray A1(5);
 
    //Calling add function to insert in List
    A1.Add(5);
    A1.Add(7);
    A1.Add(8);
    A1.Add(9);
    A1.Add(10);

    cout<<"Initial List: ";
    A1.Print();// function to print initial list

    cout<<"First element: "<<A1.Get(0)<<endl;// get first index value
    cout<<"Last element: "<<A1.Get(4)<<endl;// get last index value

    A1.Remove();// function to remove element
    cout<<"After removing last element: ";
    A1.Print();

    cout<<"List Size: "<<A1.ListSize()<<endl;
    cout<<"Maximum List Size: "<<A1.maxListSize()<<endl; //function return maximum Array size
    
    A1.clear();// clear all list
    cout<<"After clearing the list: ";
    A1.Print();
    
    return 0;
}
