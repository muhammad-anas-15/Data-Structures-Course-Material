#include <iostream>
using namespace std;

class Heap 
{
public:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size;

    Heap() 
	{
        arr[0] = -1; // Placeholder for 1-based indexing
        size = 0;
    }

    void insert(int val) 
	{
        if (size >= MAX_SIZE - 1) 
		{
            cout << "Heap overflow! Cannot insert more elements." << endl;
            return;
        }

        size += 1;
        
        int index = size;
        arr[index] = val;

        // Maintain heap property (max-heap by default)
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
    
    // Delete the root (max for max-heap, min for min-heap)
    void deleteRoot(bool isMaxHeap) 
	{
        if (size == 0) 
		{
            cout << "Heap is empty! Cannot delete root." << endl;
            return;
        }

        cout << "Deleting root: " << arr[1] << endl;
        arr[1] = arr[size]; // Move the last element to the root
        
        size--; 

        heapify(1, isMaxHeap);  // Reheapify to restore heap property
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

    void heapify(int index, bool isMaxHeap) 
	{
        int leftChild = 2 * index;
        int rightChild = 2 * index + 1;
        
        int extreme = index;

        
        if (isMaxHeap) // Max-Heap or Min-Heap check
		{
            if (leftChild <= size && arr[leftChild] > arr[extreme]) 
			{
                extreme = leftChild;
            }
            
            if (rightChild <= size && arr[rightChild] > arr[extreme]) 
			{
                extreme = rightChild;
            }
        } 
		else 
		{
            if (leftChild <= size && arr[leftChild] < arr[extreme]) 
			{
                extreme = leftChild;
            }
            
            if (rightChild <= size && arr[rightChild] < arr[extreme]) 
			{
                extreme = rightChild;
            }
        }

        if (extreme != index) 
		{
            swap(arr[extreme], arr[index]);
            
            heapify(extreme, isMaxHeap);
        }
    }

};

int main() 
{
    Heap maxHeap;

    // Inserting elements into the heap
    maxHeap.insert(50);
    maxHeap.insert(55);
    maxHeap.insert(53);
    maxHeap.insert(52);
    maxHeap.insert(54);

    cout << "Max Heap: ";
    maxHeap.Print(); // Print max-heap

    // Delete root (max element for max-heap)
    maxHeap.deleteRoot(true);
    cout << "Max Heap after deleting root: ";
    maxHeap.Print();

    Heap minHeap;

    // Inserting elements into the heap
    minHeap.insert(50);
    minHeap.insert(55);
    minHeap.insert(53);
    minHeap.insert(52);
    minHeap.insert(54);

    cout << "Min Heap: ";
    minHeap.Print(); // Print min-heap

    // Delete root (min element for min-heap)
    minHeap.deleteRoot(false);
    cout << "Min Heap after deleting root: ";
    minHeap.Print();

    return 0;
}
