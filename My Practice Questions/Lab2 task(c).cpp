#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

void display(int **ptr, int w, int d) 
{
    for (int i = 0; i < w; ++i) 
    {
        for (int j = 0; j < d; ++j) 
        {
            cout << ptr[i][j] << " ";
        }
        cout << endl;
    }
}

void hottest_day_each_Week(int **ptr, int w, int d) 
{
    for (int i = 0; i < w; ++i) 
    {
        int hightemp = ptr[i][0];
        int index = 0;

        for (int j = 1; j < d; ++j) 
        {
            if (ptr[i][j] > hightemp) 
            {
                hightemp = ptr[i][j];
                index = j;
            }
        }

        cout<<"Hottest Day of Week: "<<i+1<<" is: day "<<index + 1 <<" having a temperature "<<hightemp << " .\n";
            
    }
}

int main() 
{
    int no_of_weeks = 4;
    int no_of_days = 7;
    
    int **ptr = new int*[no_of_weeks];// Dynamically allocate rows for a 2D array
    
    for (int i = 0; i < no_of_weeks; ++i) //Dynamically allocate cols for a 2D array
    {
        ptr[i] = new int[no_of_days];
    }

    srand(time(0)); // Initialize random number generator
    
    
    for (int i = 0; i < no_of_weeks; ++i) // Fill 2D array with random temperatures .
    {
        for (int j = 0; j < no_of_days; ++j) 
        {
            ptr[i][j] = rand() %21 + 10; // Random temperature between 10°C and 30°C
        }
    }

    cout << "Temperatures for each Week:\n";
    display(ptr, no_of_weeks, no_of_days);

    cout << "\nHottest Day of Each Week:\n";
    hottest_day_each_Week(ptr, no_of_weeks, no_of_days);

    
    for (int i = 0; i < no_of_weeks; ++i) 
    {
        delete[] ptr[i];
    }
    
    delete[] ptr;
    
    return 0;
}
