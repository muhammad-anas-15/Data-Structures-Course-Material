#include <iostream>
using namespace std;

class Heap {
public:
    const int max_size = 100; // Maximum size of the heap
    int arr[max_size];
    int size;

    Heap() 
	{
        arr[0] = -1; // Placeholder for 1-based indexing
        size = 0;
    }

    void insert(int val) 
	{
        if (size >= max_size - 1) 
		{
            cout << "Heap overflow! Cannot insert more elements." << endl;
            return;
        }

        size += 1;
        int index = size;
        arr[index] = val;

        // Maintain max-heap property
        while (index > 1) 
		{
            int parent = index / 2;

            if (arr[parent] < arr[index]) 
			{
                swap(arr[parent], arr[index]);
                index = parent;
            } 
			else 
			{
                return;
            }
        }
    }

    void Print() 
	{
        if (size == 0) 
		{
            cout << "Heap is empty. Nothing to print." << endl;
            return;
        }

        for (int i = 1; i <= size; i++) 
		{
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() 
{
    Heap H1;

    // Test heap insertion
    H1.insert(50);
    H1.insert(55);
    H1.insert(53);
    H1.insert(52);
    H1.insert(54);

    // Print the heap
    H1.Print();

    // Test edge case: heap overflow
    for (int i = 0; i < 100; i++) 
	{
        H1.insert(i);
    }

    return 0;
}
